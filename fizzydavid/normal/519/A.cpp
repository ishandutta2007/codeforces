//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define input2(x,y) x=getval(),y=getval()
#define input3(x,y,z) x=getval(),y=getval(),z=getval()
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
string s[9];
int main()
{
    int a1=0,a2=0;
    for(int i=1;i<=8;i++)
    {
        cin>>s[i];
        for(int j=0;j<8;j++)
        {
            if(s[i][j]=='q')a1+=9;
            if(s[i][j]=='r')a1+=5;
            if(s[i][j]=='b')a1+=3;
            if(s[i][j]=='n')a1+=3;
            if(s[i][j]=='p')a1+=1;
            if(s[i][j]=='Q')a2+=9;
            if(s[i][j]=='R')a2+=5;
            if(s[i][j]=='B')a2+=3;
            if(s[i][j]=='N')a2+=3;
            if(s[i][j]=='P')a2+=1;
        }
    }
        if(a1<a2)puts("White");
        else if(a1>a2)puts("Black");
        else puts("Draw");
    return 0;
}