/**
 *    author:  gary
 *    created: 03.01.2022 22:14:27
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
const int MAXN=1e5+20;
int n,m;
int a[MAXN];
vector<int> b[MAXN];
LL sum[MAXN];
int ave[MAXN];
int ok[MAXN];
int ord[MAXN];
bool cmp(int A,int B){
    return ave[A]>ave[B];
}
vector<int> ans[MAXN];
int pre,suf;
int prefixsum[MAXN];
void solve(){
    cin>>n>>m;
    rb(i,1,n) cin>>a[i];
    int cntt=0;
    rb(i,1,m){
        int mi;
        cin>>mi;
        b[i].resize(mi);
        ans[i]=b[i];
        rep(j,mi) ans[i][j]=0;
        sum[i]=0;
        rep(j,mi) cin>>b[i][j],sum[i]+=b[i][j];
        ave[i]=(sum[i]+mi-1)/mi;
        ord[i]=i;
        cntt+=mi;
    }
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    n=m;
    sort(ord+1,ord+1+n,cmp);
    set<int> ss;
    rb(i,1,n){
        if(ave[ord[i]]>a[i]){
            if(i>1&&ave[ord[i]]<=a[i-1]){
                ok[i]=2;
            }
            else{
                ss.insert(i);
                continue;
            }
        }
        else{
            ok[i]=1;
            if(i!=n&&ave[ord[i]]<=a[i+1]) ok[i]=3;
        }
    }
    rb(i,1,n) prefixsum[i]=prefixsum[i-1]+(ok[i]==3);
    pre=0;
    while(pre<n&&ok[pre+1]!=2) pre++;
    suf=n+1;
    while(suf>1&&ok[suf-1]!=2) suf--;
    // rb(i,1,n){
        // cout<<ok[i]<<" ";
    // }
    // cout<<endl;
    rb(i_,1,n){
        if(ss.size()==0||(ss.size()==1&&*ss.begin()==i_));
        else continue;
        int i=ord[i_];
        rep(j,b[i].size()){
            int newave=(sum[i]-b[i][j]+b[i].size()-2)/(b[i].size()-1);
            int l=0,r=n+1;
            while(l<r-1){
                int mid=(l+r)>>1;
                if(ave[ord[mid]]<newave) r=mid;
                else l=mid;
            }
            bool flag=1;
            // i_ -> l+1
            // cout<<i<<" "<<i_<<" "<<l<<" "<<newave<<" "<<ave[1]<<" "<<a[l]<<" "<<pre<<" "<<suf<<endl;
            if(l<i_){
                flag&=(prefixsum[i_-1]-prefixsum[l])==(i_-1-l);
                flag&=pre>=l;
                flag&=suf<=i_+1;
                flag&=newave<=a[l+1];
            }
            if(l>=i_){
                flag&=newave<=a[l];
                flag&=pre>=i_-1;
                flag&=suf<=l+1;
            }
            ans[i][j]=flag;
        }
    }
    rb(i,1,n){
        rep(j,b[i].size()){
            cout<<ans[i][j];
        }
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}