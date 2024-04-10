#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=20;
int n,a[N],s;
void f(int x)
{
    if(x==n+1){
        if((s+360*20)%360==0){
            cout<<"YES";
            exit(0);
        }
        return;
    }
    s+=a[x];
    f(x+1);
    s-=2*a[x];
    f(x+1);
    s+=a[x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    f(1);
    cout<<"NO";
    return 0;
}