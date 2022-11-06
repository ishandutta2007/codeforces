#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=1e5+11;
int n,m,seed,vmax,a[N],y;
inline int pw(int n,int m){int r=1;for(;m;m>>=1,n=(ll)n*n%y)if(m&1)r=(ll)r*n%y;return r;}
inline int rnd(){
    int ret=seed;
    seed=(7ll*seed+13)%MOD;
    return ret;
}
map<int,ll>::iterator it,jt,kt;
map<int,ll> b;
inline void split(int x){
    it=b.lower_bound(x);
    if(it->fi==x)return;--it;
    b.insert(mp(x,it->se));
}
pair<ll,int> c[N];
int main(){
#ifdef flukehn
    freopen("test.txt","r",stdin);
    freopen("test.o","w",stdout);
#endif
    n=rd(),m=rd(),seed=rd(),vmax=rd();
    rep(i,1,n)a[i]=rnd()%vmax+1;
    rep(i,1,n)b.insert(mp(i,a[i]));
    b.insert(mp(n+1,0));
    int op,l,r,x;
    while(m--){
        op=rnd()%4,l=rnd()%n+1,r=rnd()%n+1;
		//dbg(op);
        if(l>r)swap(l,r);
        if (op==2)x=rnd()%(r-l+1)+1;
        else x=rnd()%vmax+1;
        //cerr<<op<<" "<<l<<" "<<r<<" "<<x<<endl;
        /*static int cnt;
        cnt+=op>1;
        if(cnt==101&&op>1)cerr<<op<<" "<<l<<" "<<r<<" "<<x<<endl;*/
        if(!op){
            split(l),split(r+1);
            jt=b.lower_bound(r+1);
            for(it=b.lower_bound(l);it!=jt;++it){
                it->se+=x;
            }
            /*for(it=b.begin();it!=b.end();++it){
				cerr<<it->fi<<" "<<it->se<<endl;
			}*/
        }else if(op==1){
            split(l),split(r+1);
            it=b.lower_bound(l),jt=b.upper_bound(r);
            it->se=x,++it;
            b.erase(it,jt);
            /*for(it=b.begin();it!=b.end();++it){
				cerr<<it->fi<<" "<<it->se<<endl;
			}*/
        }else if(op==2){
        	jt=b.upper_bound(l);//kt=b.upper_bound(r),--kt;
        	int tc=0;
            if(jt->fi>r){
                --jt;
                ll a=jt->se;
                c[++tc]=mp(a,r-l+1);//ans=(ll)pw(a,x)*(r-l+1)%MOD;
            }else{
                it=jt,--jt;
                ll a=jt->se;
                c[++tc]=mp(a,it->fi-l);//ans+=(ll)pw(a,x)*(it->fi-l)%MOD;
                kt=b.upper_bound(r),--kt;
                while(it!=kt){
                    a=it->se;
					int p=it->fi,q=(++it)->fi;
                    c[++tc]=mp(a,q-p);
					//ans+=(ll)pw(a,x)*(r-l)%MOD;
                }
                a=kt->se;
                c[++tc]=mp(a,r-kt->fi+1);
				//ans+=(ll)pw(a,x)*(r-kt->fi+1)%MOD;
            }
            sort(c+1,c+tc+1);
            int now=0;
        	rep(i,1,tc){
        		now+=c[i].se;
        		if(now>=x){
        			printf("%lld\n",c[i].fi);
        			break;
				}
			}
        }else{
            y=rnd()%vmax+1;
            //y=MOD;
            /*for(it=b.begin();it!=b.end();++it){
				cerr<<it->fi<<" "<<it->se<<endl;
			}*/
            ll ans=0;
            jt=b.upper_bound(l);//kt=b.upper_bound(r),--kt;
            if(jt->fi>r){
                --jt;
                int a=jt->se%y;
                ans=(ll)pw(a,x)*(r-l+1)%y;
                //cerr<<"ok\n";
            }else{
            	//dbg(x);
                it=jt,--jt;
                int a=jt->se%y;
                ans+=(ll)pw(a,x)*(it->fi-l)%y;
                kt=b.upper_bound(r),--kt;
                //dbg(ans);
                while(it!=kt){
                    a=it->se%y;//dbg(a);
					int c=it->fi,d=(++it)->fi;
                    ans+=(ll)pw(a,x)*(d-c)%y;
                }
                a=kt->se%y;//dbg(a);
                ans+=(ll)pw(a,x)*(r-kt->fi+1)%y;
            }
            ans%=y;
            printf("%lld\n",ans);
        }
    }
}