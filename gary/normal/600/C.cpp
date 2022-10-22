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
int main(){
	string s;
	cin>>s;
	int len=s.length();
	map<char,int>  M;
	map<char,int> :: IT ite;
	rb(i,0,len-1){
		M[s[i]]++;
	}
	vector<char> v;
	for(ite=M.begin();ite!=M.end();ite++){
		if((ite->SEC)&1){
			v.PB(ite->FIR);
		}
	}
	sort(v.begin(),v.end());
	if(v.size()&1){
		int SZ=v.size();
		rb(i,0,((SZ-1)>>1)-1){
			M[v[i]]++;
		}
		rb(i,((SZ-1)>>1)+1,SZ-1){
			M[v[i]]--;
		}
		stack<char> S;
		char CC;
		for(ite=M.begin();ite!=M.end();ite++){
			if((ite->SEC)&1){
				CC=ite->FIR;
				break;
			}
		}
		for(ite=M.begin();ite!=M.end();ite++){
			int need=(ite->SEC)>>1;
			if(ite->FIR==CC){
				continue;
			}
			if(CC<ite->FIR){
				if(M[CC]-1){
					int need2=M[CC]-1;
					need2>>=1;
					M[CC]=1;
					rb(i,1,need2){
						cout<<CC;
						S.push(CC);
					}
				}
			}
			rb(i,1,need){
				cout<<ite->FIR;
				S.push(ite->FIR);
			}
		}
		rb(i,1,M[CC]){
			cout<<CC;
		}
		while(!S.empty()){
			cout<<S.top();
			S.pop();
		}
	}
	else{
		int SZ=v.size();
		rb(i,0,(SZ>>1)-1){
			M[v[i]]++;
		}
		rb(i,SZ>>1,SZ-1){
			M[v[i]]--;
		}
		stack<char> S;
		char CC;
		for(ite=M.begin();ite!=M.end();ite++){
			if((ite->SEC)&1){
				CC=ite->FIR;
				continue;
			}
			int need=(ite->SEC)>>1;
			rb(i,1,need){
				cout<<ite->FIR;
				S.push(ite->FIR);
			}
		}
		while(!S.empty()){
			cout<<S.top();
			S.pop();
		}
	}
	return 0;
}