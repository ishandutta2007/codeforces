#include<bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define x first 
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
struct node{
	node *word[256];
	string s;
	int cnt;
	int vis;
	node(){
		for(int i=0;i<256;i++)
		word[i]=NULL;
		cnt=0;
		vis=0;
	}
}*root;
void add(char *c,int x,string s){
	node *p=root;
	for(int i=0;c[i]!=0;i++){
		if(!p->word[c[i]])p->word[c[i]]=new node();
		p=p->word[c[i]];
		if(p->vis!=x){
			p->vis=x;
			p->cnt++;
			p->s=s;
		}
	}
}
void query(char *c){
	node *p=root;
	for(int i=0;c[i]!=0;i++){
		if(!p->word[c[i]]){
			printf("0 -\n");
			return;
		}
		p=p->word[c[i]];
	}
	cout<<p->cnt<<" "<<p->s<<endl;
}
int main(){
	int n;
	scanf("%d",&n);
	root= new node();
	for(int i=1;i<=n;i++){
		char c[10];
		scanf("%s",c);
		for(int j=0;c[j]!=0;j++){
			add(c+j,i,string(c));
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		char c[10];
		scanf("%s",c);
		query(c);
	}
}