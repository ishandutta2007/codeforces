//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int AI[2750131+10];
int n;
map<int,int> MM;
void AI_SHAI(int to){
	rb(i,2,to){
		if(!AI[i]){
			int now=i+i;
			while(now<=to){
				AI[now]=1;
				now+=i;
			}
		}
	}
	int now=0;
	rb(i,2,to){
		if(!AI[i]){
			MM[i]=++now;
		}
	}
}
map<int ,int > used;
int b[400000+10];
map<int,int> greatest;
bool cmp(int A,int B) {return A>B;}
int G_DIV(int upp){
	if(!(upp&1)) return upp>>1;
	int tmp=upp;
	upp=3;
	while(1){
		if(tmp%upp==0) return tmp/upp;
		upp+=2;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	AI_SHAI(2750131); 
	rb(i,1,n<<1)
	{
		scanf("%d",&b[i]);
		used[b[i]]++;
	}
	int res=0;
	sort(b+1,b+1+(n<<1),cmp);
	rb(i,1,n<<1){
		if(res>=n) break;
		if(used[b[i]]<=0) continue;
		if(!AI[b[i]]){
			if(used[MM[b[i]]]>0){
				used[MM[b[i]]]--;
				used[b[i]]--;
				printf("%d ",MM[b[i]]);
				res++;
			}
		}
		else{
			if(!greatest[b[i]]) greatest[b[i]]=G_DIV(b[i]);
//			cout<<b[i]<<":"<<greatest[b[i]]<<endl;
			if(used[greatest[b[i]]]>0){
				used[greatest[b[i]]]--;
				used[b[i]]--;
				printf("%d ",b[i]);
				res++;
			}
		}
	}
	
	return 0;
}