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
vector<int> _from[100001];
int main(){
	int n;
	scanf("%d",&n);
	rb(i,2,n){
		int ui,vi;
		scanf("%d %d",&ui,&vi);
		_from[ui].PB(vi);
		_from[vi].PB(ui);
	}
	rb(i,1,n){
		if(_from[i].size()==2){
//			if(_from[_from[i][0]].size()==2){
				printf("NO\n");
				return 0;
//			}
		}
	}
	printf("YES\n");
	return 0;
}