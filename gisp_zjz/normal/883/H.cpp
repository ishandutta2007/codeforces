#include<bits/stdc++.h>
#define maxn 500030

using namespace std;
char s[maxn];
vector <char> p,q;
int cnt[256],n,k,t,m,j;

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for (int i=0;i<n;i++) cnt[s[i]]++;
    for (int i=0;i<256;i++) if (cnt[i]&1) k++,q.push_back(i);
    for (int i=0;i<256;i++) for (int j=0;j<cnt[i]/2;j++) p.push_back(i); m=p.size();
    if (!k){
        printf("1\n");
        for (int i=0;i<m;i++) printf("%c",p[i]);
        for (int i=m-1;i>=0;i--) printf("%c",p[i]); printf("\n");
    }
    else{
        for (int i=n;i;i--) if (n%i==0&&i>=k&&(n/i)%2==1) j=i;
        for (int i=0;i<(j-k);i++) q.push_back(p[m-1-i/2]);
        cout << j << endl;
        m=m-(j-k)/2; t=m/j;
        for (int i=0;i<j;i++)
        {
            for (int jj=i*t;jj<(i+1)*t;jj++) printf("%c",p[jj]);
            printf("%c",q[i]);
            for (int jj=(i+1)*t-1;jj>=i*t;jj--) printf("%c",p[jj]);
            printf(" ");
        }
    }
    return 0;
}