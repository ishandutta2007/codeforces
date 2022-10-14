/**
 *    author:  gary
 *    created: 29.09.2022 22:27:17
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int dp[1<<12][4005],way[1<<12][4005],state[4005][12],con[4005][12];
int C[4005],n;
mp pre[1<<12][4005];
string s[4005];
bool cmp(string A,string B){return A.length()>B.length();}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n){
        cin>>C[i];
        deque<char> dq;
        int now=-1;
        string tmp;
        cin>>tmp;
        bool vis[12]={0};
        bool bad=0;
        for(auto ch:tmp){
            if(!vis[ch-'a']){
                vis[ch-'a']=1;
                if(now+1==dq.size()||!now){
                    if(now+1==dq.size()) dq.push_back(ch),now++;
                    else dq.push_front(ch);
                }
                else{
                    bad=1;
                    break;
                }
            }
            else{
                if(now&&dq[now-1]==ch){
                    --now;
                }
                else if(now+1!=dq.size()&&dq[now+1]==ch){
                    ++now;
                }
                else{
                    bad=1;
                    break;
                }
            }
        }
        if(bad||dq.size()<=1){
            i--;n--;
            continue;
        }
        for(auto it:dq) s[i].push_back(it);
        // cout<<s[i]<<endl;
    }
    vector<string> prefix;
    prefix.push_back("");
    rb(i,1,n){
        rep(j,s[i].length()) prefix.push_back(s[i].substr(0,j+1));
        reverse(ALL(s[i]));
        rep(j,s[i].length()) prefix.push_back(s[i].substr(0,j+1));
    }
    sort(ALL(prefix));
    prefix.erase(unique(ALL(prefix)),prefix.end());
    sort(ALL(prefix),cmp);
    rep(i,prefix.size()){
        rep(c,12){
            string newstr=prefix[i];
            newstr.push_back(c+'a');
            rep(j,prefix.size()){
                if(prefix[j].empty()||(prefix[j].length()<=newstr.length()&&newstr.substr(newstr.length()-prefix[j].length(),prefix[j].length())==prefix[j])){
                    state[i][c]=j;
                    break;
                }
            }
            rb(j,1,n){
                if(s[j].length()<=newstr.length()&&newstr.substr(newstr.length()-s[j].length(),s[j].length())==s[j]){
                    con[i][c]+=C[j];
                }
                reverse(ALL(s[j]));
                if(s[j].length()<=newstr.length()&&newstr.substr(newstr.length()-s[j].length(),s[j].length())==s[j]){
                    con[i][c]+=C[j];
                }
            }
        }
    }
    rep(i,1<<12) rep(j,prefix.size()) dp[i][j]=-INF;
    dp[0][prefix.size()-1]=0;
    rep(mask,1<<12) rep(j,prefix.size()) if(dp[mask][j]>=0){
        rep(nx,12) if(!((mask>>nx)&1)) if(dp[mask|(1<<nx)][state[j][nx]]<dp[mask][j]+con[j][nx]){
            dp[mask|(1<<nx)][state[j][nx]]=dp[mask][j]+con[j][nx];
            pre[mask|(1<<nx)][state[j][nx]]=II(nx,j);
        }
    }
    mp best=II(-INF,-INF);
    rep(j,prefix.size()) check_max(best,II(dp[(1<<12)-1][j],j));
    int mask=(1<<12)-1,j=best.second;
    while (mask){
        auto temp=pre[mask][j];
        cout<<char('a'+temp.first);
        tie(mask,j)=II(mask^(1<<temp.first),temp.second);
    }
    cout<<endl;
    return 0;
}