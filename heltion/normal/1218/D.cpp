//Author: Heltion
//Date: 09-17-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1 << 17;
constexpr LL mod = 1000000007;
struct Edge{
	int u, v, w;
}e[maxn];
vector<int> G[maxn];
LL A[42][maxn];
LL B[42][maxn];
int vis[maxn], pa[maxn], dep[maxn], cn;
void DFS(int u, int p){
	vis[u] = true;
	pa[u] = p;
	for(int i : G[u]) if(i != p){
		int v = e[i].u ^ e[i].v ^ u;
		dep[v] = dep[u] + 1;
		if(not vis[v]) DFS(v, i);
	}
}
LL add(LL a, LL b){
	a += b;
	if(a >= mod) a -= mod;
	return a;
}
LL sub(LL a, LL b){
	a -= b;
	if(a < 0) a += mod;
	return a;
}
LL div2(LL a){
	if(a & 1) a += mod;
	return a >> 1;
}
void FWT(LL *a){
	for(int i = 1; i < maxn; i <<= 1)
		for(int j = 0; j < maxn; j += i << 1)
			for(int k = 0; k < i; k += 1){
				LL x = a[j + k], y = a[i + j + k];
				a[j + k] = add(x, y);
				a[i + j + k] = sub(x, y);
			}
}
void IFWT(LL *a){
	for(int i = 1; i < maxn; i <<= 1)
		for(int j = 0; j < maxn; j += i << 1)
			for(int k = 0; k < i; k += 1){
				LL x = a[j + k], y = a[i + j + k];
				a[j + k] = div2(add(x, y));
				a[i + j + k] = div2(sub(x, y));
			}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int N, M;
	cin >> N >> M;
	for(int i = 1; i <= M; i += 1){
		cin >> e[i].u >> e[i].v >> e[i].w;
		G[e[i].u].push_back(i);
		G[e[i].v].push_back(i);
	}
	DFS(1, 0);
	fill(vis + 1, vis + M + 1, false);
	for(int i = 1; i <= M; i += 1) if(pa[e[i].u] != i and pa[e[i].v] != i){
		vector<int> v;
		if(dep[e[i].u] > dep[e[i].v]) swap(e[i].u, e[i].v);
		vis[i] = true;
		v.push_back(e[i].w);
		for(int x = e[i].v; x != e[i].u; x = e[pa[x]].u ^ e[pa[x]].v ^ x){
			vis[pa[x]] = true;
			v.push_back(e[pa[x]].w);
		}
		int sum = 0;
		for(int x : v) sum ^= x;
		for(int x : v){
			A[cn][sum ^ x] += 1;
			B[cn][sum ^ x] += 1;
		}
		cn += 1;
	}
	int pans = 0, ans = maxn;
	for(int i = 1; i <= M; i += 1) if(not vis[i]) pans ^= e[i].w;
	if(cn == 0){
		cout << pans << " " << 1;
		return 0;
	}
	FWT(A[0]);
	for(int i = 1; i < cn; i += 1){
		FWT(A[i]);
		for(int j = 0; j < maxn; j += 1) A[0][j] = A[0][j] * A[i][j] % mod;
		FWT(B[0]);
		FWT(B[i]);
		for(int j = 0; j < maxn; j += 1) B[0][j] = B[0][j] * B[i][j] % mod;
		IFWT(B[0]);
		for(int j = 0; j < maxn; j += 1) B[0][j] = not not B[0][j];
	}
	IFWT(A[0]);
	for(int i = 0; i < maxn; i += 1) if(B[0][i]) ans = min(ans, pans ^ i);
	cout << ans << " " << A[0][ans ^ pans];
	return 0;
}