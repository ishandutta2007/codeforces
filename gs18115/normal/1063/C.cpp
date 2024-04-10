#include<iostream>
using namespace std;
char in[12];
inline bool query(int x,int y)
{
    cout<<x<<' '<<y<<endl;
    cin>>in;
    return in[0]=='w';
}
bool flag;
int N,i;
int l,r;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    flag=query(0,1);
    l=0;
    r=1e9;
    for(i=1;i<N;i++)
    {
        if(flag==query(l+r>>1,1))
            l=l+r>>1;
        else
            r=l+r>>1;
    }
    cout<<l<<' '<<0<<' '<<l+1<<' '<<2<<endl;
    return 0;
}