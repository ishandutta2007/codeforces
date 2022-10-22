#include <bits/stdc++.h>
int N,M,Q,a,b;
char s[1000005];
char t[1000005];
int nextval[1000005];
void get_nextval(char *t, int tlen, int *nextval)
{
    int i=0;
    nextval[0]=-1;
    int j=-1;
    while(i< tlen)
    {
        if(j==-1||t[i]==t[j])
        {
            i++;j++;
            if(t[i]!=t[j]) nextval[i]=j;
            else nextval[i]=nextval[j];
        }
        else j=nextval[j];
    }

}
int KMP(char *s,int slen, char *t, int tlen, int *nextval)//ts
{
    //get_nextval(t,tlen,nextval);
    int i=0;
    int j=0;
    int ans=0;
    while(i<slen)
    {
        if(j==-1||s[i]==t[j])
        {
            i++;j++;
        }
        else j=nextval[j];
        if(j>=tlen)
        {
            ans++;
            j=nextval[tlen];
        }
    }
    return ans;
}
int main()
{
	std::scanf("%d %d %d",&N,&M,&Q);
	std::scanf("%s",s);
	std::scanf("%s",t);
	int tlen = std::strlen(t);
	get_nextval(t,tlen,nextval);
	while (Q--)
	{
		std::scanf("%d %d",&a,&b);
		--a;
		std::printf("%d\n",KMP(s+a,b-a,t,tlen,nextval));
	}
}