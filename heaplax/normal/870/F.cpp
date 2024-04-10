#include<cstdio>
#define N 10000001
#define LL long long
int n,cnt,good,prime[N/10],non[N],mn[N],phi[N],pref_smallest_prime[N];
bool bad[N];
void pre()
{
	good=n-1;bad[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!mn[i])
		{
			if(i+i>n)bad[i]=1,--good;
			prime[++cnt]=i;
			phi[i]=i-1;
			mn[i]=i;
		}
		for(int j=1,k;j<=cnt && (k=i*prime[j])<=n;++j)
		{
			if(!mn[k])mn[k]=prime[j];
			if(i%prime[j])
			{
				phi[k]=phi[i]*phi[prime[j]];
			}
			else 
			{
				phi[k]=phi[i]*prime[j];
				break;
			}
		}
	}
	for(int i=2;i<=n;++i)
		if(mn[i]==i)non[i]=1;
		else if(mn[i/mn[i]]==mn[i])non[i]=non[i/mn[i]];
		else non[i]=non[i/mn[i]]+1;
}
LL get1()
{
	LL res=0;
	for(int i=1;i<=n;++i)
		if(!bad[i])
			res+=i-1-phi[i];
	return res;
}
LL get2()
{
	LL res=0;
	for(int i=2,j=1;i<=n;++i)
		if(mn[i] == i)++j;
		else res+=phi[i]-j+non[i];
		
	for (int i = 1; i <= n; ++i) {
        if (!bad[i]) {
            ++pref_smallest_prime[mn[i]];
        }
    }
    for (int i = 1; i <= n; ++i) {
        pref_smallest_prime[i] += pref_smallest_prime[i - 1];
    }
    for (int i = 2; i <= n; ++i) {
        if (mn[i] != i || bad[i]) continue;
        res += pref_smallest_prime[n / i];
        for (int j = i; j <= n; j += i) {
            if (mn[j] <= n / i) {
                --res;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        int a = mn[i];
        int b = i / a;
        if (b != 1 && mn[b] == b && a != b) {
            --res;
        }
    }
	return res;
}
LL calc()
{
	pre();
	LL cnt1=get1();
	LL cnt2=get2();
	LL cnt3=good*(good-1ll)/2-cnt1-cnt2;
	return cnt1+cnt2*2+cnt3*3;
}
int main()
{
	scanf("%d",&n);
	printf("%I64d\n",calc());
}