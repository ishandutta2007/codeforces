#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,a[200001],b[200001]; 
map<int,int> MM;
map<int,int> save_lo;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	rb(i,1,n) cin>>a[i];
	rb(i,1,n) cin>>b[i],MM[b[i]]=1,save_lo[b[i]]=i;
	if(b[1]==1){
		bool tmp_OK=true;
		rb(i,2,n) if(b[i]!=b[i-1]+1) tmp_OK=false;
		if(tmp_OK){
			cout<<0;
			return 0;
		} 
	}
	
	bool OK=0;
	rb(i,1,n) if(a[i]==1) OK=1;
	int final_lo=-INF;
	rb(i,1,n){
		if(b[i]==1) {
			final_lo=i;
			break;
		}
	}
	int tmp_tmp_OK=true;
	if(OK) tmp_tmp_OK=false;
	if(!OK)
	rb(i,final_lo+1,n){
		if(b[i]!=b[i-1]+1) tmp_tmp_OK=false;
	}
	if(tmp_tmp_OK){
		int res=final_lo-1;
		bool OKOKOK=1;
		rb(i,1,n){
			if(!MM[i]) continue;
			if(save_lo[i]>=final_lo) continue;
			if(save_lo[i]-i+1+(n-final_lo+1)>0){
				OKOKOK=0;
				break;
			}
		}
		if(OKOKOK){
			cout<<res<<endl;
			return 0;
		}
	}
	if(OK==0){
		int lo;
		rb(i,1,n){
			if(b[i]==1){
				lo=i;
				break;
			}
		}
		int res=n;
		int add=lo;
		rb(i,1,n){
			if(!MM[i]) continue;
			else{
				if(save_lo[i]<=lo) continue;
				else{
					if(save_lo[i]-i+1-add>0){
					add+=save_lo[i]-i+1-add;
					}
				}
			}
		}
		res+=add;
		cout<<res<<endl;
	}
	else{
//		cout<<"YES";
		int res=n;
		int add=0;
		rb(i,1,n){
			if(!MM[i]) continue;
			else{
				if(save_lo[i]-i+1-add>0){
					add+=save_lo[i]-i+1-add;
				}
			}
		}
		res+=add;
		cout<<res<<endl;
	}
	return 0;
}