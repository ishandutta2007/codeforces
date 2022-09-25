#include<bits/stdc++.h>
using namespace std;
#define N 3030
typedef long long ll;
typedef long double ld;
typedef pair<ld,ld> pdd;
const ld eps=1e-6;
const ld pipi=acos(-1.0);
int n,r_,x[N],y[N];
vector<pdd> R[N];
bool zz(ld x,ld y){return x<y+eps;}
inline ll qwq(ll x){return x*x;}
inline ld Normal(ld x){
	while(x<0)x+=2*pipi;
	while(x>2*pipi)x-=2*pipi;
	return x;
}
void init(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			ll dis=qwq(x[i]-x[j])+qwq(y[i]-y[j]);
			if(dis<=1LL*r_*r_)continue;
			ld aa=sqrt(dis);
			ld ang=asin(r_/aa);
			ld t=atan2(y[j]-y[i],x[j]-x[i]);
			ld l=Normal(t-ang);
			ld r=Normal(t+ang);
			if(zz(l,r)){
				vector<pdd> nw_R;
				for(auto Line:R[i]){
					if(zz(Line.first,Line.second)){
						Line.first=max(Line.first,l);
						Line.second=min(Line.second,r);
						if(zz(Line.first,Line.second)){
							nw_R.push_back(Line);
						}	
					}
					else{
						pdd Line1=make_pair(Line.first,2*pipi);
						pdd Line2=make_pair(0.0,Line.second);
						Line1.first=max(Line1.first,l);
						Line1.second=min(Line1.second,r);
						Line2.first=max(Line2.first,l);
						Line2.second=min(Line2.second,r);
						if(zz(Line1.first,Line1.second)){
							nw_R.push_back(Line1);
						}
						if(zz(Line2.first,Line2.second)){
							nw_R.push_back(Line2);
						}
					}
				}	
				R[i]=nw_R;
			}
			else{
				vector<pdd> nw_R;
				for(auto Line:R[i]){
					if(zz(Line.first,Line.second)){
						pdd Line1=make_pair(l,2*pipi);
						pdd Line2=make_pair(0.0,r);
						Line1.first=max(Line1.first,Line.first);
						Line1.second=min(Line1.second,Line.second);
						Line2.first=max(Line2.first,Line.first);
						Line2.second=min(Line2.second,Line.second);
						if(zz(Line1.first,Line1.second)){
							nw_R.push_back(Line1);
						}
						if(zz(Line2.first,Line2.second)){
							nw_R.push_back(Line2);
						}
					}
					else{
						pdd Line1=make_pair(Line.first,Line.second+2*pipi);
						pdd Line2=make_pair(l,r+2*pipi);
						Line1.first=max(Line1.first,Line2.first);
						Line1.second=min(Line1.second,Line2.second);
						if(zz(Line1.first,Line1.second)){
							nw_R.push_back({Line1.first,Line1.second-2*pipi});
						}
					}
				}
				R[i]=nw_R;	
			}
		}
	}	
}
int Solve(){
	int ans=0;
    for(int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            bool jb=0;
            ld pc=atan2(y[j]-y[i],x[j]-x[i]);
            while(pc<0)pc+=2*pipi;
            for(auto Line:R[i]){
                if (zz(Line.first, Line.second)){
                    jb|=zz(Line.first,pc)&&zz(pc,Line.second);
                }
				else{
                    jb|=zz(Line.first,pc)||zz(pc,Line.second);
                }
            }
            if(!jb)continue;
            jb=0;
            pc=atan2(y[i]-y[j],x[i]-x[j]);
            while(pc<0)pc+=2*pipi;
            for(auto Line:R[j]){
                if(zz(Line.first,Line.second))jb|=zz(Line.first,pc)&&zz(pc,Line.second);
				else jb|=zz(Line.first,pc)||zz(pc,Line.second);
            }
            if(!jb){
				continue;
			}
            ++ans;
        }
    }
	return ans;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>r_;
	for(int i=1;i<=n;++i){
		cin>>x[i]>>y[i];
		R[i].emplace_back(0,2*pipi);
	}
	init();
	cout<<Solve()<<'\n';
	return 0;
}