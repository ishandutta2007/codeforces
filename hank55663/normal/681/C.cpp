#include<bits/stdc++.h>
using namespace std;
#define N 505
int main(){
	priority_queue<int,vector<int>,greater<int> > pq; 
	int t;
	scanf("%d",&t);
	vector<string> ans;
	for(int i=0;i<t;i++){
		char c[1000];
		scanf("%s",c);
		if(c[0]=='i')
		{
			int n;
			scanf("%d",&n);
			pq.push(n);
			char cc[1000];
			sprintf(cc,"%s %d\n",c,n);
			ans.push_back(cc);
		}
		if(c[0]=='r'){
			char cc[1000];
			if(pq.empty())
			{
				pq.push(1);
				sprintf(cc,"insert 1\n");
				ans.push_back(cc);
			}
			pq.pop();
			sprintf(cc,"%s\n",c);
			ans.push_back(cc);
		}
		if(c[0]=='g'){
			int n;
			scanf("%d",&n);
			while(!pq.empty()&&pq.top()<n){
				pq.pop();
				char cc[1000];
				sprintf(cc,"removeMin\n");
				ans.push_back(cc);
			} 
			if(pq.empty()||pq.top()!=n)
			{
				pq.push(n);
				char cc[1000];
				sprintf(cc,"insert %d\n",n);
				ans.push_back(cc);
			}
			char cc[1000];
			sprintf(cc,"getMin %d\n",n);
			ans.push_back(cc);
		}
	}
	printf("%d\n",ans.size());
	for(vector<string>::iterator it=ans.begin();it!=ans.end();it++)
	cout<<*it;
}