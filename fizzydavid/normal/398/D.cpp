//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define input2(x,y) x=getval(),y=getval()
#define input3(x,y,z) x=getval(),y=getval(),z=getval()
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int B=450;
inline int getval()
{
	int __res=0;bool __neg=0;
	char __c;__c=getchar();
	while(__c==' '||__c=='\n')__c=getchar();
	while(__c!=' '&&__c!='\n')
	{
		if(__c=='-')__neg=1;
		else __res=__res*10+__c-'0';
		__c=getchar();
	}
	if(__neg)__res=-__res;
	return __res;
}
int n,m,q,cnt[50111];
vector<int>adj[50111],del[50111],adjbig[50111],delbig[50111];
bool on[50111],isbig[50111];
int query(int id)
{
	if(isbig[id])return cnt[id];
	else
	{
		int ans=0;
		for(int i=0;i<adj[id].size();i++)ans+=on[adj[id][i]];
		for(int i=0;i<del[id].size();i++)ans-=on[del[id][i]];
		return ans;
	}
}
void online(int id)
{
	on[id]=1;
	for(int i=0;i<adjbig[id].size();i++)cnt[adjbig[id][i]]++;
	for(int i=0;i<delbig[id].size();i++)cnt[delbig[id][i]]--;
}
void offline(int id)
{
	on[id]=0;
	for(int i=0;i<adjbig[id].size();i++)cnt[adjbig[id][i]]--;
	for(int i=0;i<delbig[id].size();i++)cnt[delbig[id][i]]++;
}
void become_big(int id)
{
	isbig[id]=1;cnt[id]=0;
	for(int i=0;i<adj[id].size();i++)
	{
		cnt[id]+=on[adj[id][i]];
		adjbig[adj[id][i]].PB(id);
	}
	for(int i=0;i<del[id].size();i++)
	{
		cnt[id]-=on[del[id][i]];
		delbig[del[id][i]].PB(id);
	}
}
void add_friend(int x,int y)
{
	adj[x].PB(y);if(isbig[y])adjbig[x].PB(y);cnt[x]+=on[y];
	adj[y].PB(x);if(isbig[x])adjbig[y].PB(x);cnt[y]+=on[x];
	if(adj[x].size()+del[x].size()>=B&&!isbig[x])become_big(x);
	if(adj[y].size()+del[y].size()>=B&&!isbig[y])become_big(y);
}
void del_friend(int x,int y)
{
	del[x].PB(y);if(isbig[y])delbig[x].PB(y);cnt[x]-=on[y];
	del[y].PB(x);if(isbig[x])delbig[y].PB(x);cnt[y]-=on[x];
	if(adj[x].size()+del[x].size()>=B&&!isbig[x])become_big(x);
	if(adj[y].size()+del[y].size()>=B&&!isbig[y])become_big(y);
}
int main()
{
	input3(n,m,q);
	int o,x,y;o=getval();
	while(o--)x=getval(),online(x);
	while(m--)input2(x,y),add_friend(x,y);
	char op;
	while(q--)
	{
		op=getchar();x=getval();
		if(op=='C')printf("%d\n",query(x));
		else if(op=='A')y=getval(),add_friend(x,y);
		else if(op=='D')y=getval(),del_friend(x,y);
		else if(op=='O')online(x);
		else if(op=='F')offline(x);
	}
	return 0;
}