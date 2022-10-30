#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
using namespace std;
long long n, p, q, i, j, cur,m, a[100005], b[100005], used[100005], vs[100005], icur, st[200005], lb, rb, dyn, ober[100005], dyn2, dyn3;
double ans, ans1, x1, x2, ans2, aac, lk, lo;
int main()
{
	cin>>n>>p>>q;
	for(i=0; i<n; i++)
	{
		cin>>a[i]>>b[i];
		vs[i]=100000000*a[i]+b[i];
	}
	sort(vs, vs+n);
	for(i=0; i<n; i++)
	{
		a[i]=vs[i]/100000000;
		b[i]=vs[i]%100000000;
	}
	for(i=0; i<n; i++)
	{
		//cout<<a[i]<<' '<<b[i]<<endl;
	}
	lb=0;
	rb=1;
	st[0]=n-1;
	for(i=n-2; i>=0; i--)
	{
		if(a[i]==a[st[rb-1]])
		{
			if(b[i]>=b[st[rb-1]])
			{
				st[rb-1]=i;
			}
		}
		else
		{
			if(b[i]>b[st[rb-1]])
			{
				if(rb>1)
				{
					dyn=(b[st[rb-1]]-b[st[rb-2]])*(a[i]-a[st[rb-2]])-(a[st[rb-1]]-a[st[rb-2]])*(b[i]-b[st[rb-2]]);
					while((dyn>=0)&&(rb>1))
					{
						//cout<<i<<endl;
						rb--;
						dyn=(b[st[rb-1]]-b[st[rb-2]])*(a[i]-a[st[rb-2]])-(a[st[rb-1]]-a[st[rb-2]])*(b[i]-b[st[rb-2]]);
					}
					st[rb]=i;
					rb++;
				}
				else
				{
					st[rb]=i;
					rb++;
				}
			}
		}
	}
	//cout<<rb<<endl;
	//cout<<a[st[0]]<<' '<<b[st[0]]<<endl;
	//cout<<a[st[1]]<<' '<<b[st[1]]<<endl;
	for(i=0; i<rb; i++)
	{
		used[st[i]]=1;
		ober[st[i]]=i;
	}
	ans=double(1999999);
	//cout<<a[st[0]]<<' '<<a[st[1]]<<endl;
	if(rb==1)
	{
		x1=double(p)/double(a[st[0]]);
		x2=double(q)/double(b[st[0]]);
		ans=max(x1, x2);
	}
	else
	{
		x1=double(p)/double(a[st[0]]);
		x2=double(q)/double(b[st[0]]);
		ans1=max(x1, x2);
		x1=double(p)/double(a[st[rb-1]]);
		x2=double(q)/double(b[st[rb-1]]);
		ans2=max(x1, x2);
		ans1=min(ans1, ans2);
		ans=ans1;
		for(i=0; i<rb-1; i++)
		{
			if((q*a[st[i]]>=p*b[st[i]]))
			{
				if(q*a[st[i+1]]<=p*b[st[i+1]])
				{
					//cout<<i<<endl;
					//cout<<a[st[i]]<<' '<<b[st[i]]<<endl;
					//cout<<a[st[i+1]]<<' '<<b[st[i+1]]<<endl;
					dyn=p*b[st[i+1]]-q*a[st[i+1]];
					dyn2=q*a[st[i]]-p*b[st[i]];
					dyn3=a[st[i]]*b[st[i+1]]-a[st[i+1]]*b[st[i]];
					lk=double(dyn)/double(dyn3);
					lo=double(dyn2)/double(dyn3);
					lk=abs(lk);
					lo=abs(lo);
					aac=lk+lo;
					ans=min(ans, aac);
				}
			}
		}
	}
	cout.precision(15);
	cout<<ans;
}

//vector<long long> v[30005];
//long long n, m, i, ic,j, price[100005], x1[100005], z1[100005], x, y, z, lc1[30005], pc1[30005],lc2[30005], rc2[30005], dist1[30005], dist2[30005], cur1, cur2, a, b, ti[100005], xf[100005], yf[100005], pr[100005], snm[10005], razm[10005], tc, xc, yc, zc, mv[100005], spis1[30005], spobr1[30005], cur, used1[30005], used2[30005], css1, css2, spis2[30005], spobr2[30005], lvl[30005], ans1, ans, dost[3][30005], avllvl1[100005], avllvl2[100005], avlpr1[100005], avlpr2[100005], avlll1[100005], avlll2[100005], avlllr1[100005], avlllr2[100005], avlmin1[100005], avlmin2[100005], xx1[100005], yy1[100005], xx2[100005], yy2[100005], num1[30005], num2[30005], zz1[100005], zz2[100005], palac1[30005], palac2[30005], lcn1[30005], rcn1[30005], lcn2[30005], rcn2[30005], ober1[30005], ober2[30005], loo1, loo2, numb1[30005], numb2[30005], kio1, kio2, kumb1[30005], kumb2[30003], gnum1[30005], gnum2[30005], uio1, uio2, oi1, oi2, lcur1, lcur2, rcur1, rcur2;
/*void dfs1(long long tt)
{
	long long iii;
	used1[tt]=1;
	if(tt<=n)
	{
		spis1[css1]=tt;
		spobr1[tt]=css1;
		css1++;
	}
	for(iii=0; iii<v[tt].size(); iii++)
	{
		if(used1[v[tt][iii]]==0)
		{
			dfs1(v[tt][iii]);
		}
	}
}
void dfs2(long long tt)
{
	long long iii;
	used2[tt]=1;
	if(tt<=n)
	{
		spis2[css2]=tt;
		spobr2[tt]=css2;
		css2++;
	}
	for(iii=0; iii<v[tt].size(); iii++)
	{
		if(used2[v[tt][iii]]==0)
		{
			dfs2(v[tt][iii]);
		}
	}
}
int main()
{ 
	cin>>n>>m;
	for(i=0; i<m; i++)
	{
		cin>>x>>y>>z;
		x1[i]=x;
		z1[i]=y;
		price[i]=z;
		ti[i]=100000*z+i;
	}
	cin>>a>>b;
	for(i=0; i<m; i++)
	{
		if(x1[i]==a)
		{
			dost[1][z1[i]]=price[i];
		}
		if(x1[i]==b)
		{
			dost[2][z1[i]]=price[i];
		}
		if(z1[i]==a)
		{
			dost[1][x1[i]]=price[i];
		}
		if(z1[i]==b)
		{
			dost[2][x1[i]]=price[i];
		}
	}
	ans1=999999999999;
	ans=999999999999;
	if(dost[1][b]>0)
	{
		ans1=dost[1][b];
	}
	for(i=1; i<=n; i++)
	{
		if(dost[1][i]>0)
		{
			if(dost[2][i]>0)
			{
				ans1=min(ans1, dost[1][i]+dost[2][i]);
			}
		}
	}
	cur1=a; 
	cur2=b;
	sort(ti, ti+m);
	for(i=0; i<m; i++)
	{
		pr[i]=ti[i]/100000;
		ic=ti[i]%100000;
		xf[i]=x1[ic];
		yf[i]=z1[ic];
	}
	for(i=0; i<m; i++)
	{
		x1[i]=xf[i];
		z1[i]=yf[i];
		price[i]=pr[i];
	}
	for(i=1; i<=n; i++)
	{
		razm[i]=1;
		snm[i]=-1;
		mv[i]=i;
		lc1[i]=i;
		pc1[i]=i;
	}
	tc=n+1;
	for(i=0; i<m; i++)
	{
		xc=x1[i];
		yc=z1[i];
		while(snm[xc]!=-1)
		{
			xc=snm[xc];
		}
		while(snm[yc]!=-1)
		{
			yc=snm[yc];
		}
		if(xc!=yc)
		{
			if(razm[xc]>razm[yc])
			{
				snm[yc]=xc;
				razm[xc]=razm[xc]+razm[yc];
				v[tc].push_back(mv[xc]);
				v[tc].push_back(mv[yc]);
				v[mv[xc]].push_back(tc);
				v[mv[yc]].push_back(tc);
				mv[xc]=tc;
				tc++;
			}
			else
			{
				snm[xc]=yc;
				razm[yc]=razm[xc]+razm[yc];
				v[tc].push_back(mv[xc]);
				v[tc].push_back(mv[yc]);
				v[mv[xc]].push_back(tc);
				v[mv[yc]].push_back(tc);
				mv[yc]=tc;
				tc++;
			}
		}
	}
	css1=1;
	css2=1;
	dfs1(cur1);
	dfs2(cur2);
	for(i=1; i<=n; i++)
	{
		razm[i]=1;
		snm[i]=-1;
		mv[i]=i;
		if(spobr1[i]>0)
		{
		    lc1[i]=spobr1[i];
		    pc1[i]=spobr1[i];
			num1[i]=0;
		}
		else
		{
			lc1[i]=999999999;
			pc1[i]=999999999;
			num1[i]=-1;
		}
	}
	tc=n+1;
	kio1=1;
	for(i=0; i<m; i++)
	{
		xc=x1[i];
		yc=z1[i];
		while(snm[xc]!=-1)
		{
			xc=snm[xc];
		}
		while(snm[yc]!=-1)
		{
			yc=snm[yc];
		}
		if(xc!=yc)
		{
			if(razm[xc]>razm[yc])
			{
				snm[yc]=xc;
				razm[xc]=razm[xc]+razm[yc];
				if(lc1[mv[xc]]<lc1[mv[yc]])
				{
					pc1[tc]=pc1[mv[yc]];
					lc1[tc]=lc1[mv[xc]];
				}
				else
				{
					lc1[tc]=lc1[mv[yc]];
					pc1[tc]=pc1[mv[xc]];
				}
				mv[xc]=tc;
				num1[tc]=price[i];
			}
			else
			{
				snm[xc]=yc;
				razm[yc]=razm[xc]+razm[yc];
				if(lc1[mv[xc]]<lc1[mv[yc]])
				{
					lc1[tc]=lc1[mv[xc]];
					pc1[tc]=pc1[mv[yc]];
				}
				else
				{
					pc1[tc]=pc1[mv[xc]];
					lc1[tc]=lc1[mv[yc]];
				}
				mv[yc]=tc;
				num1[tc]=price[i];
			}
			if(lc1[tc]==1)
			{
				kio1=pc1[tc];
			}
			else
			{
				numb1[tc]=kio1;
			}
			tc++;
		}
	}
	loo1=0;
	for(i=1; i<tc; i++)
	{
		if(lc1[i]<999999)
		{
        	palac1[loo1]=100000*num1[i]+i;
			loo1++;
		}
	}
	sort(palac1, palac1+loo1);
	for(i=0; i<loo1; i++)
	{
		ober1[i]=palac1[i]%100000;
		rcn1[i]=pc1[ober1[i]];
		lcn1[i]=lc1[ober1[i]];
		kumb1[i]=numb1[ober1[i]];
		gnum1[i]=num1[ober1[i]];
	}
	for(i=0; i<m; i++)
	{
		ti[i]=100000*min(x1[i], z1[i])+i;
	}
	sort(ti, ti+m);
	for(i=0; i<m; i++)
	{
		if(spobr1[x1[(ti[i]%100000)]]!=0)
		{
		   xx1[oi1]=min(spobr1[x1[(ti[i]%100000)]], spobr1[z1[(ti[i]%100000)]]);
		   yy1[oi1]=max(spobr1[x1[(ti[i]%100000)]], spobr1[z1[(ti[i]%100000)]]);
		   zz1[oi1]=price[(ti[i]%100000)];
		   oi1++;
		}
	}
	uio1=0;
	for(i=1; i<=n; i++)
	{
		if(spis1[i]!=0)
		{
			uio1++;
		}
	}
}*/