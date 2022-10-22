//* AuThOr GaRyMr *//
//AFT ST
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
map<mp,char> c;
map<int,int> row;
map<int,int> colum;
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int n,m;
		row.clear();
		colum.clear();
		scanf("%d %d",&n,&m);
		rb(i,1,n){
		rb(j,1,m){
			cin>>c[{i,j}];
		}
		}
		rb(i,1,n)
		rb(j,1,m)
			if(c[{i,j}]=='*'){
				row[i]++;
				colum[j]++;
			}
		int res=INF;
		rb(i,1,n){
			rb(j,1,m){
					int tot;
					tot=colum[j]+row[i]-bool(c[{i,j}]=='*');
					res=min(res,n+m-1-tot);
			}
		}
		printf("%d\n",(res==INF)? n+m-1:res);
	}
	return 0;
}