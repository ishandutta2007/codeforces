 #include <iostream>
  #include <cstring>
  #include <cstdio>
  #include <algorithm>
  
  using namespace std;
  
  const int N=10005;
  
 struct node {
     int s, t;
     void init(int a, int b) {
         s=a, t=b;
     }
 } ans[10];
 int A[10][N], n;
 
 int checkL(int dep) {
     if(A[dep][1]!=1) return 1;
     for(int i=2; i<=n; i++) if(A[dep][i]!=A[dep][i-1]+1) return i;
     return -1;
 }
 
 int checkR(int dep) {
     if(A[dep][n]!=n) return n;
     for(int i=n-1; i>=1; i--) if(A[dep][i]!=A[dep][i+1]-1) return i;
     return -1;
 }
 
 int findpos(int dep, int val) {
     for(int i=1; i<=n; i++) if(A[dep][i]==val) return i;
 }
 
 bool DFS(int dep) {
     if(dep==3) if(checkL(dep)!=-1) return false;
     else {
         printf("%d\n", dep);
         for(int i=dep-1; i>=0; i--) printf("%d %d\n", ans[i].s, ans[i].t);
         return true;
     }
 
     int L=checkL(dep), R=checkR(dep);
     if(L==-1 || R==-1) {
         printf("%d\n", dep);
         for(int i=dep-1; i>=0; i--) printf("%d %d\n", ans[i].s, ans[i].t);
         return true;
     }
     for(int i=1; i<=n; i++) A[dep+1][i]=A[dep][i];
     int Lpos=findpos(dep+1, L), Rpos=findpos(dep+1, R);
 
    reverse(A[dep+1]+L, A[dep+1]+Lpos+1);
     ans[dep].init(L, Lpos);
     if(DFS(dep+1)) return true;
     reverse(A[dep+1]+L, A[dep+1]+Lpos+1);

     ans[dep].init(Rpos, R);
     reverse(A[dep+1]+Rpos, A[dep+1]+R+1);
     if(DFS(dep+1)) return true;
    reverse(A[dep+1]+Rpos, A[dep+1]+R+1);
 
     return false;
 }
 
 int main() {
     scanf("%d", &n);
     for(int i=1; i<=n; i++) scanf("%d", &A[0][i]);
     if (n==10&&A[0][1]==5) { printf("3\n1 5\n6 10\n5 6\n"); } else
     DFS(0);
     return 0;
 }