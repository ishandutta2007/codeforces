#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back

const int MAXN = 100*1000+1;
int n;
int a[2*MAXN];
LL minPole;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<2*n;i++) cin>>a[i];
    sort(a,a+2*n);
    minPole = (LL)(a[n-1] - a[0])*(a[2*n-1]-a[n]);
    for(int i=n; i<2*n-1;i++) {
        minPole=min(minPole,(LL)(a[2*n-1]-a[0])*(a[i]-a[i-n+1]));
    }
    cout<<minPole;
}