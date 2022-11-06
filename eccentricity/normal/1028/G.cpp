#include<bits/stdc++.h>
#define ll long long
using namespace std;
void ask(ll x){
	
}
ll tr;
vector<ll>que;
ll ask(){
	printf("%d ",que.size());
	for (int i=0;i<que.size();i++) printf(" %lld",que[i]); printf("\n"); fflush(stdout);
	int x=0;
	scanf("%d",&x);
	
	/*for (int i=0;i<que.size();i++){
		if (que[i]==tr){
			//printf("%lld !!!\n",que[i]);
			x=-1;
		}
	}
	
	if (x!=-1){
		if (tr<que[0]) x=0;
		else{
			for (int i=0;i<que.size();i++) if (tr>que[i]) x=i+1;
		}
	}*/
	
	if (x==-1) exit(0);
	if (x==-2) assert(0);
	return x;
}

ll calc(int q,ll x){
	//printf("DFS %d %lld\n",q,x);
	//if (x>10000) return 0;
	if (q==1){
		return min(x*2-1,x+9999);
	}
	if (x>=10000){
		if (q==2) return x+10001*10001-2;
	}
	ll cs,now;

		cs=x,now=cs;
	
		for (int i=1;i<=min(10000ll,cs)+1;i++){
			ll tmp=calc(q-1,now);
			now=tmp+2;
		}
		return now-2;
}

void dfs(int q,ll x){
	//printf("DFS %d %lld\n",q,x);
	//if (x>10000) return 0;
	if (q==1){
				//printf("???\n");
		que.clear();
				//printf("???\n");
		for (ll i=x;i<=min(x*2ll-1,x+9999ll);i++) que.push_back(i);
		//printf("???\n");
		ask();
		return;
	}
	if (x>=10000){
		if (q==2){
			que.clear();
			for (int i=1;i<=10000;i++) que.push_back(x+i*10001ll-1);
			int tmp=ask();
			dfs(q-1,x+tmp*10001);
			return;
		}
	}
	ll cs,now;

		cs=x,now=cs;
		
		que.clear();
		for (int i=1;i<=min(10000ll,cs)+1;i++){
			ll tmp=calc(q-1,now);
			//printf("%lld\n",tmp);
			if (i<=min(10000ll,cs)) que.push_back(tmp+1);
			//if (q==2) printf("%lld\n",tmp);
			now=tmp+2;
		}
		ll tmp=ask();
		if (tmp==0) dfs(q-1,x); else
		dfs(q-1,que[tmp-1]+1);
}
int main(){
	//printf("%lld\n",calc(3,1));
	//tr=1ll*rand()%10004205361450474+1;
	//printf("%lld\n",tr);
	dfs(5,1);
	//printf("%lld\n",dfs(5,1));
}