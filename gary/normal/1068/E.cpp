//* AuThOr MrGaRy *//
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,k;
map<int,int> each[100000+10];
int have[100000+10];
int all_[100000+10];
int is_now[100000+10];
int bye[100000+10];
queue<mp> q;
map<int,int> in_it;
int main(){
	scanf("%d %d",&n,&k);
	rep(i,n-1){
		int ui,vi;
		scanf("%d %d",&ui,&vi);
		each[ui][vi]=1;
		each[vi][ui]=1;
		have[ui]++;
		have[vi]++;
		all_[ui]++;
		all_[vi]++; 
	}
	rb(i,1,n){
		if(have[i]==1){
			q.push(II(i,0));
			is_now[i]=0;
			in_it[i]=true;
		}
	}
	map<int,int> :: IT ite;
	int root;
	while(!q.empty()){
		int now=q.front().FIR;
		int now2=q.front().SEC;
		q.pop();
		bye[now]=1;
		if(have[now]==0){
			if(!q.empty()){
				puts("No");
				return 0;
			}
			if(now2==k){
				root=now;
				break;
			}
			else{
				puts("No");
				return 0;
			}
		}
		else{
			if(have[now]==1){
				
			}
			else{
				puts("No");
				return 0;
			}
		}
		for(ite=each[now].begin();ite!=each[now].end();ite++){
			if(!in_it[ite->FIR]){
				in_it[ite->FIR]=true;
				have[ite->FIR]--;
				is_now[ite->FIR]=now2+1;
				q.push(II(ite->FIR,now2+1));
			}
			else{
				have[ite->FIR]--;
				if(!bye[ite->FIR]&&is_now[ite->FIR]!=now2+1){
//					cout<<ite->FIR<<" "<<is_now[ite->FIR]<<endl;
					puts("No");
					return 0;
				} 
			}
		}
	}
//	cout<<root<<endl;
	rb(i,1,n){
		if(i==root){
			if(all_[i]<3) {
				puts("No");
				return 0;
			}
		} 
		else{
			if(all_[i]!=1&&all_[i]<4){
				puts("No");
				return 0;
			}
		} 
	}
	puts("Yes");
	return 0;
}