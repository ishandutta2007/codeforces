#include <bits/stdc++.h>

using namespace std;

#define MAXN 30

char mp[1005][1005];
int hash[35];
int num[35];

int i,j,t,k;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	t = rd();
    for (i=0;i<1000;i++)
        for (j=0;j<1000;j++)
            mp[i][j]='N';
    k=1;
    for (i=2;;) {
        if (MAXN-k+1<0) break;
        hash[MAXN-k+1]=i;
        j=0;
        if (i>2) {
            int tmp=hash[MAXN-k+2];
            for (j=0;j<k;j++) {
                if (j==0 || j==k-1) mp[i+j][tmp]=mp[tmp][i+j]='Y';
                else {
                    mp[i+j][tmp]=mp[tmp][i+j]='Y';
                    tmp++;
                    mp[tmp][i+j]=mp[i+j][tmp]='Y';
                }
                if (MAXN-k+1==0) mp[i+j][0]=mp[0][i+j]='Y';
            }
        }

        i+=k;
        k++;
    }
    int n=i,up=0;
    while(t) {
        num[up++]=t%2;
        t/=2;
    }
    for (i=0;i<up;i++) {
        if (num[i]==0) continue;
        int tmp=hash[i];
        for (j=i;j<MAXN;j++) {
            mp[tmp][n]=mp[n][tmp]='Y';
            tmp=n;
            n++;
        }
        mp[n-1][1]=mp[1][n-1]='Y';
    }
    printf("%d\n",n);
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++)
            printf("%c",mp[i][j]);
        printf("\n");
    }
    return 0;
}