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
int u[100001],n;
map<int,int> tot;
map<int,int> _have;
void CLEAR(int x){
	tot[_have[x]--]--;
	tot[_have[x]]++;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	rb(i,1,n) cin>>u[i];
	rb(i,1,n){
		_have[u[i]]++;
		tot[_have[u[i]]]++;
		if(_have[u[i]]!=1) tot[_have[u[i]]-1]--;
	}
	rl(i,n,1){
		map<int,int> :: IT iter;
		int num1=INF,num2=INF,tot1,tot2;
		bool OK=1;
		for(iter=tot.begin();iter!=tot.end();){
			if(iter->SEC==0||iter->FIR==0){
				tot.erase(iter++);
				continue;
			}
			if(num1==INF){
				num1=iter->FIR;
				tot1=iter->SEC;
			}
			else{
				if(num2==INF){
					num2=iter->FIR;
					tot2=iter->SEC;
				}
				else{
					OK=0;
				}
			}
			iter++;
		}
		if(OK==1){
			if(num2!=INF){
			if(abs(num1-num2)!=1) OK=0;
			else{
				if(num1-num2==1){
					if(tot1!=1) OK=0; 
				}
				else{
					if(tot2!=1) OK=0; 
				}
			} 
			if(num2==1&&tot2==1) OK=1;
			if(num1==1&&tot1==1) OK=1;
		}
		else if(num1!=1&&tot1!=1)OK=0;
		}
		CLEAR(u[i]);
		if(OK){
			cout<<i<<endl;
			return 0;
		}
		else{
			continue;
		}
	}
	return 0;
}