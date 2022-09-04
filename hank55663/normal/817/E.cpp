#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define EPS 1e-11
#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
struct trie{
	trie* a[2];
	int num;
	trie(){
		a[0]=a[1]=NULL;
		num=0; 
	}
}*root;
void add(int x){
	vector<int> v;
	while(x){
		v.pb(x&1);
		x>>=1;
	}
	while(v.size()<30)v.pb(0);
	trie* n=root;
	while(!v.empty()){
	//printf("%d",v.back());
		if(!n->a[v.back()])
		n->a[v.back()]=new trie;
		n=n->a[v.back()];
		n->num++;
		v.pop_back();
	}
	//printf("\n");
}
void erase(int x){
	vector<int> v;
	while(x){
		v.pb(x&1);
		x>>=1;
	}
	while(v.size()<30)v.pb(0);
	trie* n=root;
	while(!v.empty()){
		n=n->a[v.back()];
		n->num--;
		v.pop_back();
	}
} 
void search(int x,int y){
	vector<int> v;
	while(x){
		v.pb(x&1);
		x>>=1;
	}
	while(v.size()<30)v.pb(0);
	vector<int> v2;
	while(y){
		v2.pb(y&1);
		y>>=1;
	}
	while(v2.size()<30)v2.pb(0);
	int num=0;
	trie *n=root;
//	printf("?");
	while(v.size()){
	//	printf("%d",v.back());
		if(v2.back()==1){
			if(!n)
			break;
			if(n->a[v.back()]){
			//	printf("?");
		//		printf(" %d %d",num,v.back());
				num+=n->a[v.back()]->num;
			//	printf("%d\n",num);
				//printf("!\n");
			}
		}
	//	printf("!");
		n=n->a[v.back()^v2.back()];
		if(!n)
		break;
		v.pop_back();
		v2.pop_back(); 
	}
	//printf("%d\n",num);
	printf("%d\n",num);
}
int main(){	
	int q;
	scanf("%d",&q);
	root=new trie();
	while(q--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x;
			scanf("%d",&x);
			add(x);
		}
		else if(op==2){
			int x;
			scanf("%d",&x);
			erase(x);
		}
		else{
			int x,y;
			scanf("%d %d",&x,&y);
			search(x,y);
			
		}
	}
}
/*
12321   3*9=27
*/