#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 30005
#define next Next
#define index Index
struct Node{
	Node *index[30];
	Node *fail;
	int word;
	int num;
	Node(){
		for(int i=0;i<30;i++)
		index[i]=NULL;
		fail=NULL;
		word=0;
		num=-1;
	}
}*root=new Node();
int t;
void add(char c[]){
	Node *n=root;
	for(int i=0;c[i]!=0;i++){
		
		if(!n->index[c[i]-'a'])
		n->index[c[i]-'a']=new Node();
		n=n->index[c[i]-'a'];
	}
	n->word=1;
	n->num=++t;
}
void ac(){
	queue<Node*> q;
	q.push(root);
	root->fail=NULL;
	while(!q.empty()){
		Node *n=q.front();
		q.pop();
		for(int i=0;i<30;i++){
			if(n->index[i]){
				q.push(n->index[i]);
				Node* p=n->fail;
				while(p!=NULL&&!p->index[i])
				p=p->fail;
				if(p)
				n->index[i]->fail=p->index[i];
				else
				n->index[i]->fail=root;
			}
		}
	} 
}
int num[2000005];
void search(char c[]){
	Node *n=root;
	for(int i=0;c[i]!=0;i++){
		
		while(!n->index[c[i]-'a']&&n!=root){
			n=n->fail;
		}
		if(n->index[c[i]-'a'])
		n=n->index[c[i]-'a'];
        if(n->word){
            num[i]=n->num;
        }
    }
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[2000005];
    scanf("%s",c);
    int g;
    scanf("%d",&g);
    for(int i = 0;i<g;i++){
        char tmp[1000005];
        scanf("%s",tmp);
        add(tmp);
    }
    ac();
    for(int i = n*k;i<n*k*2;i++){
        c[i]=c[i-n*k];
        c[i+1]=0;
    }
    search(c);
    //for(int i = 0;i<n*k*2;i++){
     //   printf("%d ",num[i]);
   // }
    for(int i = k-1;i<2*k-1;i++){
        int ok=1;
        vector<int> v;
        set<int> s;
        int now=i;
        for(int  j =0;j<n;j++){
            if(num[now]==0){
                ok=0;
            }
            v.pb(num[now]);
            s.insert(num[now]);
            now+=k;
        }
        if(ok&&v.size()==s.size()){
            printf("YES\n");
            for(auto it:v)
            printf("%d ",it);
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */