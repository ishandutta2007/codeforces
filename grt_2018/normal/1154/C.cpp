#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

int a,b,c;
vi week = {0,1,2,0,2,1,0,0,1,2,0,2,1,0,0};
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c;
    int full = min({a/3,b/2,c/2});
    a -= full*3;
    b -= full*2;
    c -= full*2;
    vi ile = {a,b,c};
    int ind=0;
    for(int start=0; start<7; start++) {
        while(ile[0]>=0&&ile[1]>=0&&ile[2]>=0) {
            ile[week[ind]]--;
            ind++;
        }
        ind--;
        ile[week[ind]]++;
        //cout<<ind<<" "<<start<<" "<<ile[0]<<" "<<ile[1]<<" "<<ile[2]<<"\n";
        ans=max(ans,ind-start);
        ile[week[start]]++;
    }
    cout<<ans+full*7;
}