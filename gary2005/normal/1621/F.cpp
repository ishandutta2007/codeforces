/**
 *    author:  gary
 *    created: 03.01.2022 22:14:31
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int n,a,b,c;
LL solve(vector<int>& bet,int one,int lazy,int yet,int lazy2,bool turn){
    if(turn==0){
        LL answer=0;
        if(bet.size()||lazy) answer=a;
        if(bet.size()&&yet){
            bet.back()--;
            if(bet.back()==1){
                one++;
                bet.POB();
            }
            check_max(answer,solve(bet,one,lazy,yet,lazy2,1)+a);
        }
        else{
            if(yet==0&&one==0){
            }
            else
            if(yet==0){
                one--;
                yet++;
                check_max(answer,solve(bet,one,lazy,yet,lazy2,1)-c);
            }
            else
            if(one==0&&lazy==0&&lazy2==0){
            }
            else
            if(lazy){
                lazy--;
                check_max(answer,solve(bet,one,lazy,yet,lazy2,1)+a);
            }
            else{
                if(one){
                    one--;
                    yet++;
                    check_max(answer,solve(bet,one,lazy,yet,lazy2,1)-c);
                }
                else{
                    lazy2--;
                    check_max(answer,solve(bet,one,lazy,yet,lazy2,1)-c);
                }
            }
        }
        return answer;
    }
    else{
        if(yet==0) return 0;
        return solve(bet,one,lazy,yet-1,lazy2,0)+b;
    }
    return 0;
}
void solve(){
    string s;
    cin>>n>>a>>b>>c;
    cin>>s;
    vector<int> pos;
    rep(i,n) if(s[i]=='1') pos.PB(i+1);
    int cnt[2]={0,0};
    rep(i,n-1){
        if(s[i]==s[i+1]) cnt[s[i]-'0']++;
    }
    if(c>=b||pos.size()<=1){
        LL answer=0;
        int mn=min(cnt[0],cnt[1]);
        answer=1ll*min(mn+1,cnt[0])*a+1ll*min(mn+1,cnt[1])*b;
        cout<<answer<<endl;
        return;
    }
    int one,lazy,yet;
    one=lazy=yet=0;
    vector<int> bet;
    rep(i,pos.size()-1){
        int z=pos[i+1]-pos[i]-1;
        if(z==0){
            yet++;
        }
        if(z==1){
            one++;
        }
        if(z>1){
            bet.PB(z);
        }
    }
    lazy=max(0,pos[0]-2)+max(0,n-pos.back()-1);
    int lazy2=(pos[0]!=1)+(pos.back()!=n);
    sort(ALL(bet));
    reverse(ALL(bet));
    auto old=bet;
    cout<<max(solve(bet,one,lazy,yet,lazy2,0),solve(old,one,lazy,yet,lazy2,1))<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}