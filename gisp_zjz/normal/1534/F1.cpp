#include<bits/stdc++.h>
#define maxn 2000020
using namespace std;
int N,M;
string S[maxn];
int to[maxn],nxt[maxn],h[maxn],low[maxn],dfn[maxn],n,m,p,colorcnt,instack[maxn],color[maxn];
bool visit[maxn],in[maxn];
vector <int> s;

void add_edge(int x,int y){
	p++;
	to[p]=y;
	nxt[p]=h[x];
	h[x]=p;
}

void dfs(int x){
	p++;
	instack[x]=1;
	dfn[x]=p;
	low[x]=dfn[x];
	s.push_back(x);
	for (int i=h[x];i;i=nxt[i]){
		if (!instack[to[i]]){
			dfs(to[i]);
			low[x]=min(low[x],low[to[i]]);
		}
		else if (instack[to[i]]==1) low[x]=min(low[x],dfn[to[i]]);
	}
	if (dfn[x]==low[x]){
		while (s.back()!=x){
			color[s.back()]=colorcnt;
			instack[s.back()]=2;
			s.pop_back();
		}
		color[s.back()]=colorcnt++;
		instack[s.back()]=2;
		s.pop_back();
	}
}

int id(int x,int y){return (N-x)*M+y+1;}
int A[maxn];
int main(){
    cin >> N >> M; p=0;
	memset(h,0,sizeof(h));
	memset(nxt,0,sizeof(nxt));
    for (int i=N;i;i--) cin >> S[i];
    for (int i=0;i<M;i++) cin >> A[i];
    for (int i=N;i;i--)
    for (int j=0;j<M;j++) if (S[i][j]=='#'){
        int x=id(i,j);
        int ii=i-1;
        while (ii>0&&S[ii][j]=='.') ii--;
        if (ii>0) add_edge(x,id(ii,j));
        if (i<N&&S[i+1][j]=='#') add_edge(x,id(i+1,j));
        for (int r=i;r>ii;r--){
            if (j>0&&S[r][j-1]=='#') add_edge(x,id(r,j-1));
            if (j<M-1&&S[r][j+1]=='#') add_edge(x,id(r,j+1));
        }
    }
	memset(instack,0,sizeof(instack));
	colorcnt=1;p=0;
    for (int i=N;i;i--)
    for (int j=0;j<M;j++) if (S[i][j]=='#'){
        int x=id(i,j);
        if (!instack[x]) dfs(x);
    }
    int ans=colorcnt-1;
    for (int i=N;i;i--)
    for (int j=0;j<M;j++) if (S[i][j]=='#'){
        int x=id(i,j);
        for (int t=h[x];t;t=nxt[t]){
            int y=to[t];
            if (color[x]!=color[y]){
                if (!in[color[y]]){
                    in[color[y]]=1;
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;

	return 0;
}