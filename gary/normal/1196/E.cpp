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
void solve(){
	int b,w;
	cin>>b>>w;
	if(b<w){
		if(b*3+1<w){
			puts("NO");
			return ;
		}
		//put the 
		puts("YES");
		w-=b;
		int now=3;
		rb(i,1,b){
			printf("%d %d\n",2,now); 
			now++;
			printf("%d %d\n",2,now); 
			now++;
		}
		if(w){
			w--;
			printf("%d %d\n",2,2);
		}
		int rest=w;
		now=3;
		rb(i,1,b){
			if(!rest) break;
			printf("1 %d\n",now);
			rest--;
			now+=2;
		}
		now=3;
		rb(i,1,b){
			if(!rest) break;
			printf("3 %d\n",now);
			rest--;
			now+=2;
		}
	}
	else{
		swap(b,w);
		if(b*3+1<w){
			puts("NO");
			return ;
		}
		puts("YES");
		w-=b;
		int now=4;
		rb(i,1,b){
			printf("%d %d\n",2,now); 
			now++;
			printf("%d %d\n",2,now); 
			now++;
		}
		if(w){
			w--;
			printf("%d %d\n",2,3);
		}
		int rest=w;
		now=4;
		rb(i,1,b){
			if(!rest) break;
			printf("1 %d\n",now);
			rest--;
			now+=2;
		}
		now=4;
		rb(i,1,b){
			if(!rest) break;
			printf("3 %d\n",now);
			rest--;
			now+=2;
		}
	}
}
int main(){
	int q;
	cin>>q;
	while(q--){
		solve();
	}
	return 0;
}