/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> co[100000+10],ro[100000+10],co2[100000+10],ro2[100000+10];
int main(){
	int n,m;
	cin>>n>>m;
	int k;
	cin>>k;
	rb(i,1,k){
		int xi,yi;
		scanf("%d %d",&xi,&yi);
		ro[xi].PB(yi);
		co[yi].PB(xi);
		ro2[xi].PB(yi);
		co2[yi].PB(xi); 
	}
	int x,y;
	x=y=1;
	int di=1;
	LL tmp=0;
	int lasx,lasy,a,b,c,d;
	a=0,b=m+1,c=0,d=n+1;
	lasx=lasy=-1;
	while(n>=1){
//		cout<<di<<endl;
		if(di==1){
//			cout<<"s"<<endl;
			di++;
			int Is;
			ro[x].PB(a);
			ro[x].PB(b);
			sort(ALL(ro[x])); 
			for(auto it: ro[x]){
				if(it>y){
					Is=it;
					break;
				}
			}
			tmp+=Is-y-1;
			c=x;
//			cout<<x<<" "<<y<<endl;
//			cout<<tmp<<endl;
			
			y=Is-1;
		}
		else{
			if(di==2){
				di++;
				int Is;
				co[y].PB(c);
				co[y].PB(d);
//				cout<<d<<endl; 
				sort(ALL(co[y])); 
				for(auto it:co[y]){
					if(it>x){
						Is=it;
						break;
					}
				}
				tmp+=Is-x-1;
				x=Is-1;
				b=y;
//				cout<<tmp<<endl;
			}
			else{
				if(di==3){
					di++;
					int Is;
					ro[x].PB(a);
					ro[x].PB(b);
					sort(ALL(ro[x])); 
					for(auto it:ro[x]){
						if(it<y){
							Is=it;
						}
					}
					tmp+=y-Is-1;
					y=Is+1;
					d=x;
				}
				else{
					di=1;
					int Is;
					co[y].PB(c);
					co[y].PB(d);
					sort(ALL(co[y])); 
					for(auto it:co[y]){
						if(it<x){
							Is=it;
						}
					}
					tmp+=x-Is-1;
					x=Is+1;
					a=y;
				}
			}
		}
		if(lasx==x&&lasy==y) break;
		lasx=x;
		lasy=y;
//		cout<<x<<"--"<<y<<endl;
 	}
 	tmp++;
// 	cout<<tmp<<" "<<x<<" "<<y<<" "<<di<<endl;
 	LL save=tmp;
 	tmp=0;
 	x=y=1;
	a=0,b=m+1,c=0,d=n+1;
	lasx=lasy=-1;
	di=2;
	rb(i,1,n) ro[i]=ro2[i];
	rb(i,1,m) co[i]=co2[i];
	while(n>=1){
		if(di==1){
//			cout<<"s"<<endl;
			di++;
			int Is;
			ro[x].PB(a);
			ro[x].PB(b);
			sort(ALL(ro[x])); 
			for(auto it: ro[x]){
				if(it<y){
					Is=it;
//					break;
				}
			}
			tmp+=Is-y-1;
			c=x;
			y=Is+1;
//			cout<<x<<" "<<y<<endl;
//			cout<<tmp<<endl;
			
		}
		else{
			if(di==2){
				di++;
				int Is;
				co[y].PB(c);
				co[y].PB(d);
				sort(ALL(co[y])); 
//				cout<<d<<endl
				for(auto it:co[y]){
//					cout<<it<<endl;
					if(it>x){
						Is=it;
						break;
					}
				}
//				cout<<Is<<endl;
				tmp+=Is-x-1;
				x=Is-1;
				a=y;
//				cout<<tmp<<endl;
			}
			else{
				if(di==3){
					di++;
					int Is;
					ro[x].PB(a);
					ro[x].PB(b);
					sort(ALL(ro[x])); 
					for(auto it:ro[x]){
						if(it>y){
							Is=it;
							break;
						}
					}
					tmp+=y-Is-1;
					y=Is-1;
					d=x;
				}
				else{
					di=1;
					int Is;
					co[y].PB(c);
					co[y].PB(d);
					sort(ALL(co[y])); 
					for(auto it:co[y]){
						if(it<x){
							Is=it;
						}
					}
					tmp+=x-Is-1;
					x=Is+1;
					b=y;
				}
			}
		}
//		cout<<x<<," "<<y<<endl;
		if(lasx==x&&lasy==y) break;
		lasx=x;
		lasy=y;
 	}
 	tmp++; 
 	tmp=max(save,tmp);
	if(tmp!=(LL)(n)*m-k){
		puts("No");
	}
	else{
		puts("Yes");
	}
	return 0;
}