#include<cstdio>
#include<stack>
char s[300005];
int main()
{
    int n;
    scanf("%d",&n);
    if(n&1)
    {
        printf(":(\n");
        return 0;
    }
    int half=n>>1,cnt1=0,cnt2=0;
    scanf("%s",s+1);
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='(')
        {
            ++cnt1;
        }
        else if(s[i]==')')
        {
            ++cnt2;
        }
    }
    for(int i=1;i<=n;++i)
    {
    	if(s[i]=='?')
    	{
	        if(cnt1<half)
    	    {
        	    s[i]='(';
            	++cnt1;
	        }
    	    else
        	{
	            s[i]=')';
    	        ++cnt2;
        	}
        }
    }
    if(cnt1!=cnt2)
    {
        printf(":(\n");
        return 0;
    }
    std::stack<int> st;
    
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='(')
        {
            st.push(1);
        }
        else
        {
            if(!st.empty())
            {
                st.pop();
            }
            else
            {
                if(i!=n) 
                {
                    printf(":(\n");
                    return 0;
                }
            }
        }
        if(i!=n)
        {
            if(st.empty())
            {
                printf(":(\n");
                return 0;
            }
        }
        else
        {
            if(!st.empty())
            {
                printf(":(\n");
                return 0;
            }
        }
    }
    printf("%s",s+1);
    return 0;
}