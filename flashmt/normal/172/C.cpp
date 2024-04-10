#include <iostream>
#include <algorithm>
using namespace std;

struct student
{
	int t,x,id;
	
	void input(int _id)
	{
		cin >> t >> x;
		id=_id;
	}
};

bool operator < (const student &u,const student &v)
{
	return u.x<v.x;
}

int n,m,ans[100000];
student a[100000];

int main()
{
	cin >> n >> m;
	for (int i=0;i<n;i++) a[i].input(i);
	
	int T=0;
	for (int i=0;i<n;)
	{
		int j=min(i+m,n),last=0;
		T=max(T,a[j-1].t);
		sort(a+i,a+j);
		
		for (int p=i;p<j;)
		{
			int q;
			for (q=p+1;q<j && a[q].x==a[p].x;q++);
			T+=a[p].x-last;
			for (int k=p;k<q;k++) ans[a[k].id]=T;
			T+=1+(q-p)/2;
			last=a[p].x;
			p=q;
		}
		
		T+=last;
		i=j;
	}
	
	for (int i=0;i<n;i++) cout << ans[i] << ' ';
}