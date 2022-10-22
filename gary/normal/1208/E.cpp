//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,w;
LL addline[1000000+10],res[1000000+10];// 
vector<LL> a[1000000+10];
/*
for(i,1:n)
	if(li<=w/2)
		res[1 ~ w-li]+=max(max(a[i]),0)//
		res[w-li+1 ~ w]+=max(max(a[i][j] ~ a[i][li])0,)//it from the 		last to begin
	else
		for(j,1:w)
			slip(l,r,j)
			renew the res[j]
void slip(l,r,index)
	while(pop the useless);
	while(pop the wore than now);
	add;
*/
LL maxi[1000000+10];
int dq[1000000+1000000+100];
int h,t;
void slip(int l,int r,int index){
	if(t>=h)
	while(t>=h&&dq[h]<l) ++h;
	if(t>=h)
	while(t>=h&&a[index][dq[t]]<=a[index][r]) --t;
	dq[++t]=r;
}
int main(){
	memset(maxi,-0x3f,sizeof(maxi));
	cin>>n>>w;
	rep(i,n){
		int li;
		scanf("%d",&li);
		rep(j,li) {
			LL ai;
			scanf("%I64d",&ai);
			a[i+1].PB(ai);
			maxi[i+1]=max(maxi[i+1],ai);
		}
	}
	rb(i,1,n){
//		cout<<i<<"-----"<<endl;
		int li=a[i].size();
		if(li<=(w>>1)){
			addline[li]+=max(maxi[i],(LL)(0));
			addline[w-li+1]-=max(maxi[i],(LL)(0));
			LL tmp=0,it=a[i].size();
			rl(j,w,w-li+1){
				tmp=max(tmp,a[i][--it]);
				res[j]+=tmp;
			}
			tmp=0,it=-1;
			rb(j,1,li-1){
				tmp=max(tmp,a[i][++it]);
				res[j]+=tmp;
//				cout<<j<<" "<<tmp<<" "<<it<<endl;
			}
		}
		else{
			h=0;
			t=-1;
			rb(j,1,w){
				int l_bound,r_bound;
				if(j<=w-li+1){
					l_bound=1;
					r_bound=j;
				}
				else{
					l_bound=j-(w-li+1)+1;
					r_bound=min(li,j);
				}
				slip(l_bound-1,r_bound-1,i);
				LL another=-INF;
				if(j<w-li+1||j>li) another=0;
				res[j]+=max(a[i][dq[h]],another);
			}
		}
	}
	
	rb(i,1,w) addline[i]+=addline[i-1],res[i]+=addline[i];
	rb(i,1,w) printf("%I64d ",res[i]);puts("");
	return 0;
}