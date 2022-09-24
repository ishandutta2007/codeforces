#include<iostream>
using namespace std;
bool flag;
char C[12];
char S[123456];
bool que(int a,int b,int c,int d)
{
    cout<<"? "<<a+1<<' '<<b+1<<' '<<c+1<<' '<<d+1<<endl;
    cin>>C;
    return C[0]=='Y';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,x,y,i;
    cin>>N;
    x=y=i=0;
    while(x+y<N-1)
    {
        if(que(x+1,y,N-1,N-1))
        {
            S[i++]='D';
            x++;
        }
        else
        {
            S[i++]='R';
            y++;
        }
    }
    x=y=N-1;
    i=(N<<1)-2;
    while(x+y>=N)
    {
        if(que(0,0,x,y-1))
        {
            S[--i]='R';
            y--;
        }
        else
        {
            S[--i]='D';
            x--;
        }
    }
    cout<<"! "<<S<<endl;
    return 0;
}