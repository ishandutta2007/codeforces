#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,ll>
using namespace std;
const int N= 1e5+100;
const int mod= 1e9+7;
int n,m,seed,mn;
int num[N];
map<int,pii> mp;
int rnd(){
    int ret = seed;
    seed = (7LL*seed+13)%mod;
    return ret;
}

ll qpow(int x,int b,int p){
    ll sum = 1;
    ll now = x;
    while(b){
        if(b&1) sum = sum*now%p;
        now = now*now%p;
        b >>= 1;
    }
    return sum;
}

void solve(int op,int l,int r,int x,int y){
    if(op == 1){
        int now = 1;
        while(now <= r){
            pair<int,ll> &tmp = mp[now];
            if(tmp.first >= l){
                if(now < l){
                    mp[l] = tmp;
                    tmp.first = l-1;
                }
                else{
                    if(tmp.first <= r){
                        tmp.second += x;
                    }
                    else{
                        mp[r+1] = tmp;
                        tmp.first = r;
                        tmp.second += x;
                    }
                }
            }
            now = tmp.first+1;
        }
    }
    else if(op == 2){
        int now = 1;
        while(now <= r){
            pair<int,ll> &tmp = mp[now];
            if(tmp.first >= l){
                if(now < l){
                    mp[l] = tmp;
                    tmp.first = l-1;
                }
                while(mp[now].first <= r){
                    now = mp[now].first+1;
                }
                mp[r+1] = mp[now];
                mp[l] = make_pair(r,x);
                now = l;
            }
            now = mp[now].first+1;
        }
    }
    else if(op == 3){
        int now = 1;
        vector<pair<ll,int> > v;
        while(now <= r){
            pair<int,ll> &tmp = mp[now];
            if(tmp.first >= l){
                v.push_back({tmp.second,min(r,tmp.first)-max(l,now)+1});
            }
            now = tmp.first+1;
        }
        sort(v.begin(),v.end());
        int bef = 0;

        for(int i = 0;i < v.size();i ++){
            bef += v[i].second;
            if(bef >= x){
                printf("%lld\n",v[i].first);
                break;
            }
        }
    }
    else if(op == 4){
        ll ans = 0;
        int now = 1;
        while(now <= r){
            pair<int,ll> &tmp = mp[now];
            if(tmp.first >= l){
                ans =(ans+ 1LL*(min(r,tmp.first)-max(l,now)+1)*qpow((int)(tmp.second%y),x,y))%y;
            }
            now = tmp.first+1;
        }
        printf("%lld\n",ans);
    }

}


int main(){
    scanf("%d %d %d %d",&n,&m,&seed,&mn);
    for(int i = 1;i <= n;i ++){
        num[i] = rnd()%mn+1;
        //cout <<i << ' '<< num[i] << endl;
        mp[i] = make_pair(i,num[i]);
    }
    mp[n+1] = make_pair(n+1,0);
    for(int i = 1;i <= m;i ++){
        int op,l,r,x,y=0;
        op = rnd()%4+1;
        l = rnd()%n+1;
        r = rnd()%n+1;
        if(l > r) swap(l,r);
        if(op == 3) x = rnd()%(r-l+1)+1;
        else x = rnd()%mn+1;
        if(op == 4) y = rnd()%mn+1;
        //cout<<"!!" <<op << ' '<< l << ' '<< r << ' '<< x << ' '<< y << endl;
        solve(op,l,r,x,y);

    }
    return 0;
}