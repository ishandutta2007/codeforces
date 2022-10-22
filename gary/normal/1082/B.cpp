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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int totg=0;
vector<mp> seg(100000+10); 
int main(){
	int n;
	string s;
	cin>>n;
	cin>>s;
	rb(i,0,n-1){
		totg+=(s[i]=='G');
	}
	int tot=0;
	rb(i,0,n-1){
		if(i==0){
			
			if(s[i]=='S'){
				continue;
			}
			else{
				seg[++tot]=II(0,0);
			}
			continue;
		}
		if(s[i]=='S'){
			continue;
		}
		if(s[i]=='G'&&s[i-1]=='G'){
			seg[tot].SEC++;
		}
		if(s[i]=='G'&&s[i-1]=='S'){
			seg[++tot]=II(i,i);
		}
	}
	int res=0;
	rb(i,1,tot){
		int tmp_res=0;
		tmp_res=seg[i].SEC-seg[i].FIR+1;
		if(tmp_res<totg) tmp_res++;
		res=max(res,tmp_res);
	}
	rb(i,2,tot){
		if(seg[i].FIR==seg[i-1].SEC+2){
			int tmp_tot=seg[i].SEC-seg[i].FIR+1+seg[i-1].SEC-seg[i-1].FIR+1;
			if(tmp_tot<totg){
				tmp_tot++;
			}
			res=max(res,tmp_tot);
		}
	}
	printf("%d\n",res);
	return 0;
}