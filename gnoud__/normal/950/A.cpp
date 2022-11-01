#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<int,int>
#define MAX(a,b,c) max(max(a,b),c)
#define fi first
#define se second
using namespace std;
int l,r,a;
bool check(int i)
{
    if(i-l>a||i-r>a) return false;
    if(i-l+i-r<=a) return true;
    return false;
}
int main()
{
    cin>>l>>r>>a;
    int tg=(l+r+a)/2;
    fordec(i,tg,0)
    {
        if(check(i))
        {
            cout<<i*2;
            return 0;
        }
    }
}