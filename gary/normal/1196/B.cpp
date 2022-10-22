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
int a[200000+10];
int main(){
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		int k;
		int tot=0;
		scanf("%d",&k);
		rb(i,1,n){
			scanf("%d",&a[i]);
			tot+=(bool(a[i]&1));
		}//int ri=1;
		if(tot>=k&&(tot-k+1)&1){
			cout<<"YES"<<endl;
			int ri=1;
			rb(i,1,k-1)
			for(ri;ri<=n;ri++){
				if(a[ri]&1){
					cout<<ri<<" ";
					ri++;
					break;
				}
				
			}
			cout<<n<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	} 
	return 0;
}