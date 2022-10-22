#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
const LL INF = (LL)1000*1000*1000*1000*1000*1000;

int n,k,a,b;
LL l;
LL ansmax,ansmin=INF;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>a>>b;
    for(auto f:{1,-1}) {
        for(auto s:{1,-1}) {
            for(int x=0; x<=n;x++) {
                l = (LL)k*x + (f*a + s*b)%k;
                //cout<<l<<"\n";
                if(l<=0) continue;
                ansmax = max(ansmax,((LL)n*k)/(__gcd((LL)n*k,l)));
                ansmin = min(ansmin,((LL)n*k)/(__gcd((LL)n*k,l)));
            }
        }
    }
    cout<<ansmin<<" "<<ansmax<<"\n";
    return 0;
}