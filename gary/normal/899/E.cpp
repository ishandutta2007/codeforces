//* AuThOr GaRyMr *//
/*
 node
1. length
2. *next
3. ty

<,st,*is>
used  
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
struct node
{
	int len,ty,st,id;
	node *next,*prev;
};
priority_queue< pair<mp,node *> > q;
int used[200000+10];
node now[200000+10];
int main(){
	int ai,las=-1,have=0;
	int has=1;	
	cin>>n;
	rb(i,1,n){
		cin>>ai;
		if(ai!=las){
			if(have==0){
				now[1].id=1;
				now[1].len=1;
				now[1].prev=NULL;
				now[1].st=1;
				now[1].ty=ai;
				have=1;
			}
			else{++has;
				now[has].id=has;
				now[has].len=1;
				now[has-1].next=&now[has];
				now[has].prev=&now[has-1];
				now[has].st=i;
				now[has].ty=ai;
			}
		}
		else{
			now[has].len++;
		}
		las=ai;
	}
	now[has].next=NULL;
	rb(i,1,has){
		q.push(II(II(now[i].len,-now[i].st),&now[i]));
//		cout<<now[i].len<<" "<<now[i].st<<" "<<now[i].id<<endl;
	}
	int res=0;
//	cout<<"OK"<<endl;
	KEEP{
		int Is=-1;pair<mp,node* > tmp;
		while(!q.empty()){
			tmp=q.top(),q.pop();
			if(used[(tmp.SEC)->id]){
				 continue;
			}
			else{
				Is=1;
				break;
			}
		}
		if(Is==-1) break;
		res++;
		node * cur=tmp.SEC;//
//		cout<<cur->id<<" "<<cur->len<<endl;
		used[cur->id]=1;
		if(cur->next!=NULL)(*(cur->next)).prev=((*(cur)).prev);
		if(cur->prev!=NULL)((*(cur->prev)).next)=cur->next;
		if(cur->next!=NULL){
		cur=cur->next;
		if(cur->prev!=NULL){
			if((cur->prev)->ty==cur->ty){
				(cur->prev)->len+=cur->len;
				used[(cur)->id]=1;
				if(cur->next!=NULL)(*(cur->next)).prev=((*(cur)).prev);
				if(cur->prev!=NULL)((*(cur->prev)).next)=cur->next;
				cur=cur->prev;
				q.push(II(II(cur->len,-cur->st),cur));
			}
		}
		}
	}
	cout<<res<<endl;
	return 0;
}