#include<cstdio>
#include<cstring>
const int MAXN = 1e5 + 5;

char s[MAXN];
bool del[MAXN];
int a[4];

int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	int m=0;
	for(int i=1; i<=n; ++i)
		m=(m+s[i])%3;
	
	if(!m){ printf("%s",s+1); return 0;}
	
	for(int i=1; i<=n; ++i) ++a[s[i]%3];
	
	int cnt=0;
	for(int i=2; i<=n && s[i]=='0'; ++i) ++cnt;
	
	if(a[m] && n>1 && (cnt<=1 || a[m]>1 || s[1]%3!=m))
		--a[m];
	else if(a[3-m]>1 && n>2)
		a[3-m]-=2;
	else if(a[m] && n>1)
		--a[m];
	else
	{
		printf("-1");
		return 0;
	}
	
	bool flag=0;
	for(int i=1; i<=n; ++i)
    {
        if(s[i]=='0' && !flag)
            continue;
        if(a[s[i]%3])
        {
            putchar(s[i]);
            a[s[i]%3]--;
            flag=1;
        }
    }
    if(!flag)
        printf("0");
	return 0;
}