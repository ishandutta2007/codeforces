#include<stdio.h>
#include<climits>
using namespace std;
const int sz = 400001;
int n, a[sz], deg[sz], gi[sz], gv[sz], u[sz], v[sz], ord[sz], st[sz], stsz, oc[sz];
long long tot[sz], ch1[sz];
bool vis[sz];
long long mininf = LLONG_MIN;
int main()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++)
	scanf("%i",&a[i]);
    for(int i=0;i<n;i++)
	deg[i] = 0;
    for(int i=0;i<n-1;i++)
    {
	scanf("%i%i",&u[i],&v[i]);
	u[i]--;
	v[i]--;
	deg[u[i]]++;
	deg[v[i]]++;
    }
    gi[0] = 0;
    for(int i=1;i<n;i++)
	gi[i] = gi[i-1]+deg[i-1];
    for(int i=0;i<n;i++)
	deg[i] = 0;
    for(int i=0;i<n-1;i++)
    {
	gv[gi[u[i]]+deg[u[i]]] = v[i];
	deg[u[i]]++;
	gv[gi[v[i]]+deg[v[i]]] = u[i];
	deg[v[i]]++;
    }

    for(int i=0;i<n;i++)
	vis[i] = false;
    st[0] = 0;
    stsz = 1;
    int k = 0;
    while(stsz>0)
    {
	stsz--;
	int i = st[stsz];
	vis[i] = true;
	ord[k]  = i;
	k++;
	for(int j=0;j<deg[i];j++)
	    if(!vis[gv[gi[i]+j]])
	    {
		st[stsz] = gv[gi[i]+j];
		stsz++;
	    }
    }
    for(int i=0;i<n;i++)
	oc[ord[i]] = i;
    // for(int i=0;i<n;i++)
    // 	printf("%i\n",oc[i]);
    long long o1, o2, best;
    best = mininf;
    for(int t=n-1;t>=0;t--)
    {
	int i = ord[t];
	tot[i] = a[i];
	ch1[i] = mininf;
	o1 = mininf;
	o2 = mininf;
	
	for(int t2=0;t2<deg[i];t2++)
	{
	    int j = gv[gi[i]+t2];
	    if(oc[j]>oc[i])
	    {
		tot[i]+=tot[j];
		if(ch1[j]>ch1[i])
		    ch1[i] = ch1[j];
		if(ch1[j]>o1)
		{
		    o2 = o1;
		    o1 = ch1[j];
		}
		else if(ch1[j]>o2)
		    o2 = ch1[j];
		
	    }
	}
	// printf("%i: %lli\n",i+1,tot[i]);
	if(tot[i]>ch1[i])
	    ch1[i] = tot[i];
	
	if(o1>mininf && o2>mininf && o1+o2>best)
	    best = o1+o2;
    }
    if(best==mininf)
	printf("Impossible\n");
    else
	printf("%lli\n",best);
}