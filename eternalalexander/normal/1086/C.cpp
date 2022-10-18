#include <bits/stdc++.h>
#define maxn 1000005
char a[maxn],b[maxn],s[maxn];
int n,k,vis[30],ref[30],h[30],g[30],p[maxn],l[maxn],r[maxn];
int assign(int x,int y){
//	printf("try %d %d\n",i,j);
	if((vis[x] || ref[y]) && ! (vis[x] == y)) return 0;
	vis[x] = y; ref[y] = x;
//	printf("%d -> %d\n",y,x);
	return 1;
}

void clear() {
	for(int i=1;i<=k;++i){
		if(ref[i])continue;
		for(int j=1;j<=k;++j)if(assign(j,i))break;
	}
}


void record() {
	std::memcpy(h,vis,sizeof(h));
	std::memcpy(g,ref,sizeof(g));
}

void recover() {
	std::memcpy(vis,h,sizeof(h));
	std::memcpy(ref,g,sizeof(g));
}

int checka() {
	for(int i=1;i<=n;++i){
		if(vis[p[i]]>l[i])return 1;
		if(vis[p[i]]<l[i])return 0;
	}return 1;
}

int checkb(){
	for(int i=1;i<=n;++i){
		if(vis[p[i]]<r[i])return 1;
		if(vis[p[i]]>r[i])return 0;
	}return 1;
}
		

int check(){
	return checka() && checkb();
}

int find_min(int i,int output=0) {
	for(int j=i;j<=n;++j) {
		if (vis[p[j]]) continue;
		for(int l=1;l<=k;++l) if (assign(p[j],l)) break;
	}
	if(check()) { puts("YES"); clear(); for (int i=1;i<=k;++i) printf("%c",vis[i]+'a'-1); 
	puts(""); return 1; }
	else {
		if (output) puts("NO");
		return 0;
	}
}
int find_max(int i,int output=0) {
//	printf(">");
	for(int j=i;j<=n;++j) {
		if (vis[p[j]]) continue;
		for(int l=k;l>=1;--l) if (assign(p[j],l)) break;
	}
//	for(int i=1;i<=n;++i)printf("%c",vis[p[i]]+'a'-1);puts("");
	if(check()) { 
		puts("YES"); clear(); for (int i=1;i<=k;++i) printf("%c",vis[i]+'a'-1); 
		puts(""); return 1; }
	else {
		if (output) puts("NO");
		return 0;
	}
}

void solve(){
	std::memset(vis,0,sizeof(vis));
	std::memset(ref,0,sizeof(ref));
	scanf("%d%s%s%s",&k,s+1,a+1,b+1);
	n=std::strlen(s+1);
	for(int i=1;i<=n;++i){
		p[i]=s[i]-'a'+1;
		l[i]=a[i]-'a'+1;
		r[i]=b[i]-'a'+1;
	}for(int i=1;i<=n;++i){
		if(l[i] == r[i]) {
			//printf("assign %d %d\n",p[i],l[i]);
			if (!assign ( p[i], l[i] )) { puts("NO"); return ; }
		}
		else {
		//	printf("%d %d\n",vis[p[i]],l[i]);
			if (vis[p[i]]) {
				if (vis[p[i]] > r[i] || vis[p[i]] < l[i] ) { puts("NO"); return ; }
				if (l[i] < vis[p[i]] && vis[p[i]] < r[i] ) { assert(find_min(i,1)); return ; }
				if (vis[p[i]] == l[i]) { find_max(i,1); return ; }
				if (vis[p[i]] == r[i]) { find_min(i,1); return ; }
			}
			else {
				for (int j = l[i] + 1; j < r[i]; ++ j) 
					if ( assign(p[i], j) ) { assert(find_min(j+1,1)); return ; }
				record();
				if ( assign(p[i],l[i]) ) if (find_max(i+1)) return ;
				recover();
				if ( assign(p[i],r[i]) ) if (find_min(i+1)) return;
				puts("NO");
				return ;
			} return;
		}
	} puts("YES");
	clear();
	for (int i=1;i<=k;++i) printf("%c",vis[i]+'a'-1);
	puts("");
}

int main(){
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}