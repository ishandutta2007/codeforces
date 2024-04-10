#include<bits/stdc++.h>
using namespace std;
int read(){int x;scanf("%d",&x);return x;}
struct Node{
	int i;
	long long v;
	bool operator<(const Node&rhs)const{
		if(v<rhs.v)return 1;
		if(v==rhs.v&&i<rhs.i)return 1;
		return 0;
	} 
};
bool cmp(const Node&a,const Node&b){
	return a.i<b.i;
}
int main(){
	int N=read();
	set<Node> q;
	vector<Node> v;
	for(int i=0;i<N;i++){q.insert((Node){i,read()});}
	while(!q.empty()){
		Node node1=*q.begin();
		q.erase(q.begin());
		if(q.empty())v.push_back(node1);
		else{
			Node node2=*q.begin();
			if(node1.v==node2.v){
				q.erase(q.begin());
				q.insert((Node){node2.i,node2.v*2});
			}
			else v.push_back(node1);
		}
	}
	sort(v.begin(),v.end(),cmp);
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++)
		printf("%lld ",v[i].v);
}