#include<bits/stdc++.h>
using namespace std;
long long aa,bb,cc,a,b,c,hs,d,e,f,g,hso,hs1,hs2;
int main()
{
	cin>>a>>b>>c;
	aa=min((a+1)%3+2,a);
	bb=min((b+1)%3+2,b);
	cc=min((c+1)%3+2,c);
	hs=hs+((a-aa)/3);
	hs=hs+((b-bb)/3);
	hs=hs+((c-cc)/3);
	/*d=min(aa,bb);
	d=min(d,cc);
	f=max(aa,bb);
	f=max(f,cc);
	e=aa+bb+cc-d-f;*/
	
	e=aa;f=bb;g=cc;
	hs1=hs1+aa/3;
	aa=aa%3;
	hs1=hs1+bb/3;
	bb=bb%3;
	hs1=hs1+cc/3;
	cc=cc%3;
	d=min(aa,bb);
	d=min(d,cc);
	hs1=hs1+d;
	
	d=min(e,f);
	d=min(d,g);
	hs2=d;
	e=e-hs2;
	f=f-hs2;
	g=g-hs2;
	hs2=hs2+e/3;
	hs2=hs2+f/3;
	hs2=hs2+g/3;
	hso=max(hs1,hs2);
	
	cout<<hs+hso<<endl;
}