#include<bits/stdc++.h>
#define maxn 205030

using namespace std;
vector <int> a[maxn];
int n,m,k,cnt;

int main()
{
    scanf("%d%d",&n,&m);
    if (n==1&&m==1) {printf("YES\n1\n");return 0;}
    if (n==3&&m==3)
    {
        printf("YES\n1 6 4\n7 2 8\n5 9 3\n");return 0;
    }
    else if (n<=3&&m<=3) printf("NO\n");
    else if (n<=4&&m<=4){
        printf("YES\n");
        if (n==4&&m==1) printf("3\n1\n4\n2\n");
        else if (n==4&&m==2) printf("1 6\n4 7\n5 2\n8 3\n");
        else if (n==4&&m==3) printf("1 8 3\n5 12 4\n7 2 9\n11 6 10\n");
        else if (n==1&&m==4) printf("3 1 4 2\n");
        else if (n==2&&m==4) printf("5 4 7 2\n3 6 1 8\n");
        else if (n==3&&m==4) printf("1 10 3 12\n7 4 5 2\n9 6 11 8\n");
        else if (n==4&&m==4) printf("1 14 3 16\n7 4 5 2\n9 6 11 8\n15 12 13 10\n");
        return 0;
    }
    else if (m>4){
        cnt=0;k=m/2;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m/2;j++)
            {
                a[i].push_back(cnt+j+k);
                a[i].push_back(cnt+j);
            }
            if (m&1) a[i].push_back(cnt+m);
            cnt+=m;
        }
        printf("YES\n");
        for (int i=1;i<=n;i++)
        {
            if (i&1) {
                for (int j=0;j<m;j++) printf("%d ",a[i][j]);
                printf("\n");
            }
            else {
                if (m&1){
                    for (int j=1;j<m;j++)printf("%d ",a[i][j]);
                    printf("%d\n",a[i][0]);
                }
                else {
                    for (int j=0;j<m/2;j++) printf("%d %d ",a[i][j*2+1],a[i][j*2]);
                    printf("\n");
                }
            }
        }
    }
    else{
        for (int i=1;i<=m;i++)
        {
            int r=0; k=n/2;
            for (int j=1;j<=k;j++)
            {
                a[r].push_back((j+k-1)*m+i); r++;
                a[r].push_back((j-1)*m+i); r++;
            }
            if (n&1) a[r].push_back((n-1)*m+i); r++;
        }
        printf("YES\n");
        for (int i=0;i<n;i++)
        {
            if (n&1) for (int j=0;j<m;j++)printf("%d ",a[(i+(j&1))%n][j]);
            else for (int j=0;j<m;j++)printf("%d ",a[i^(j&1)][j]);
            printf("\n");
        }
    }
    return 0;
}