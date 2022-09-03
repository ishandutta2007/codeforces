#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
struct node{
	node *n[26];
	int word;
	node(){
		word=0;
		for(int i = 0;i<26;i++)
		n[i]=NULL;
	}
}*root;
void add(char *c){
	node *n=root;
	for(int i = 0;c[i]!=0;i++){
		if(!n->n[c[i]-'a'])n->n[c[i]-'a']=new node();
		n=n->n[c[i]-'a'];
	}
	n->word++;
}
int ans=0;
multiset<int> merge(multiset<int> s1,multiset<int> s2){
	if(s1.size()<s2.size())swap(s1,s2);
	for(auto it:s2)
	s1.insert(it);
	return s1;
}
multiset<int> dfs(node *n,int dep){
	//printf("%d\n",dep);
	if(!n)return multiset<int>();
	//printf("x%d\n",dep);
	multiset<int> s;
	for(int i = 0;i<26;i++){
		s=merge(s,dfs(n->n[i],dep+1));
	}
	if(n->word)
	ans+=dep;
	else{
		int x=*s.rbegin();
		s.erase(s.find(x));
		ans-=x;
		ans+=dep;
	}
	s.insert(dep);
	return s;
}
int main(){
	int n;
	scanf("%d",&n);
	char c[100005];
	root= new node();
	for(int i = 0;i<n;i++){
		scanf("%s",c);
		add(c);
	}
	for(int i = 0;i<26;i++)
	dfs(root->n[i],1);
	printf("%d\n",ans);
}