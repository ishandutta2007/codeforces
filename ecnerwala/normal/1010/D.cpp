#include<bits/stdc++.h>
const int MAXN = 1e6+20;
int N;
char O[MAXN];
int D[MAXN][2];
int T[MAXN];
bool V[MAXN];
bool F[MAXN];
bool q(int i) {
switch(O[i]) {
case 'I': return D[i][0]+1;
case 'N': return !V[D[i][0]];
case 'A': return V[D[i][0]]&V[D[i][1]];
case 'O': return V[D[i][0]]|V[D[i][1]];
case 'X': return V[D[i][0]]^V[D[i][1]];
}
assert(false);
}
char R[MAXN];
int main() {
scanf("%d", &N);
for (int i = 0; i < N; i++) {
scanf(" %s", &O[i]);
if (O[i]=='I'||O[i] == 'N') scanf("%d", &D[i][0]);
else scanf("%d %d", &D[i][0], &D[i][1]);
D[i][0]--;
D[i][1]--;
}
for (int l=0,r=1; l<N; l++) {
int i=T[l];
if (O[i]== 'I') continue;
T[r++] = D[i][0];
if (O[i]=='N') continue;
T[r++] = D[i][1];
}
for (int z=N-1;z>=0;z--) {
int i=T[z];
V[i]=q(i);
}
F[0]=1;
for (int z=0;z<N;z++){
int i=T[z];
if(!F[i]) continue;
if (O[i]=='I') continue;
if (O[i]=='N') F[D[i][0]]=1;
if (O[i]=='X') F[D[i][0]]=F[D[i][1]]=1;
if (O[i]=='A') F[D[i][0]]=V[D[i][1]],F[D[i][1]]=V[D[i][0]];
if (O[i]=='O') F[D[i][0]]=!V[D[i][1]],F[D[i][1]]=!V[D[i][0]];
}
for (int i = 0,j=0; i < N; i++) {
if (O[i]=='I') {
R[j++]=(F[i]^V[0])+'0';
}
}
printf("%s\n", R);
}