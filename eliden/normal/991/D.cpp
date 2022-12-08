#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    int n=sz(s1);
    vi block(n);
    rep(i,0,n) {
        if(s1[i]=='X') block[i]+=1;
        if(s2[i]=='X') block[i]+=2;
    }
    int NEGINF=-(1<<25);
    if(n<2) cout << "0\n";
    else {
        vi dp(4,NEGINF);
        dp[block[0]]=0;
        vi mask1{3,3,1,2}, mask2{2,1,3,3};
        rep(i,1,n) {
            vi next(4,NEGINF);
            int x=NEGINF;
            rep(j,0,4) x=max(x,dp[j]);
            next[block[i]]=x;
            rep(j,0,4) rep(move,0,4) {
                if((j&mask1[move])==0 && (block[i]&mask2[move])==0) {
                    int ms= block[i]|mask2[move];
                    next[ms] = max(next[ms],1+dp[j]);
                }
            }
            swap(dp,next);
        }
        int best=NEGINF;
        rep(j,0,4) best=max(best,dp[j]);
        cout << best << "\n";
    }
}