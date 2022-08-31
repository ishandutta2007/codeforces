#include <iostream>
#include <string>
using namespace std;

int lm(int xd[3][3],int a,int b,int c)
{
    return xd[0][a]+xd[1][b]+xd[2][c];
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int d[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    for(int i=0;i<n;i++)
    {
        if(i%3==0)
        {
            if(s.at(i)=='R') d[0][0]++;
            else if(s.at(i)=='G') d[0][1]++;
            else if(s.at(i)=='B') d[0][2]++;
        }
        else if(i%3==1)
        {
            if(s.at(i)=='R') d[1][0]++;
            else if(s.at(i)=='G') d[1][1]++;
            else if(s.at(i)=='B') d[1][2]++;
        }
        else if(i%3==2)
        {
            if(s.at(i)=='R') d[2][0]++;
            else if(s.at(i)=='G') d[2][1]++;
            else if(s.at(i)=='B') d[2][2]++;
        }
    }
    int xd[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            xd[i][j]=d[i][(j+1)%3]+d[i][(j+2)%3];
        }
    }
    int a=0,b=1,c=2;
    if(lm(xd,0,2,1)<lm(xd,a,b,c))
    {
        a=0;
        b=2;
        c=1;
    }
    if(lm(xd,1,0,2)<lm(xd,a,b,c))
    {
        a=1;
        b=0;
        c=2;
    }
    if(lm(xd,1,2,0)<lm(xd,a,b,c))
    {
        a=1;
        b=2;
        c=0;
    }
    if(lm(xd,2,0,1)<lm(xd,a,b,c))
    {
        a=2;
        b=0;
        c=1;
    }
    if(lm(xd,2,1,0)<lm(xd,a,b,c))
    {
        a=2;
        b=1;
        c=0;
    }
    for(int i=0;i<n;i+=3)
    {
        if(a==0) s.at(i)='R';
        else if(a==1) s.at(i)='G';
        else if(a==2) s.at(i)='B';
    }
    for(int i=1;i<n;i+=3)
    {
        if(b==0) s.at(i)='R';
        else if(b==1) s.at(i)='G';
        else if(b==2) s.at(i)='B';
    }
    for(int i=2;i<n;i+=3)
    {
        if(c==0) s.at(i)='R';
        else if(c==1) s.at(i)='G';
        else if(c==2) s.at(i)='B';
    }
    cout<<lm(xd,a,b,c)<<'\n'<<s;


    return 0;
}