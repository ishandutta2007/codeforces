#include <cstdio>
#include <string>
#include <algorithm>

// this is the first time that I use a pointer.
// thank you for m.kagamiz

class prefix_tree{
	public:

	struct Trie{
		Trie *next[2];
	};

	Trie stack[4000000],*root;
	int wp;

	Trie *make(){
		Trie *ret=&(stack[wp++]);
		for(int i=0;i<2;i++){
			ret->next[i]=(Trie *)0;
		}
		return ret;
	}

	void insert(Trie *P,long long q){
		int x[45];
		for(int i=44;i>=0;i--){
			x[i]=q%2;
			q/=2;
		}
		for(int i=0;i<=44;i++){
			if(!P->next[x[i]]){
				P->next[x[i]]=make();
			}
			P=P->next[x[i]];
		}
	}

	long long find(Trie *P,long long as){
		long long po=0;
		int a[45];
		for(int i=44;i>=0;i--){
			a[i]=as%2;
			as/=2;
		}
		for(int i=0;i<=44;i++){
			if(P->next[(1-a[i])]){
				po=po*2+1;
				P=P->next[(1-a[i])];
			}else{
				po*=2; P=P->next[a[i]];
			}
		}
		return po;
	}
};

prefix_tree maximization;
int n;
long long num[100005];

int main(){

	maximization.root=maximization.make();
	scanf("%d",&n);
	long long X=0,Y=0;

	maximization.insert(maximization.root,X);
	long long ans=0,Z;

	for(int i=1;i<=n;i++){
		scanf("%lld",&num[i]);
		X^=num[i];
	}
	
	Z=X;
	for(int i=0;i<=n;i++){
		if(i){
			Y^=num[i];
			maximization.insert(maximization.root,Y);
			Z^=num[i];
			ans=std::max(ans,maximization.find(maximization.root,Z));
		}else{
			ans=std::max(ans,maximization.find(maximization.root,Z));
		}
	}

	printf("%lld\n",ans);
	return 0;
}