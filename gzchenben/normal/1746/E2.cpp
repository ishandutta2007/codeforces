#include<cstdio>
#include<vector>
using namespace std;
int n,cnt;
vector<int> vec[2];

char s[10];
bool Ask(vector<int> &cur)
{
    // cnt++;
    // return false;
    printf("? %d",cur.size());
    for(auto &p : cur)
        printf(" %d",p);
    printf("\n");
    fflush(stdout);
    scanf("%s",s+1);
    if(s[1] == 'Y') return true;
    else return false;
}


int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        vec[0].push_back(i);
    while(vec[0].size() + vec[1].size() >= 3)
    {
        // printf("siz = %d %d\n",vec[0].size(),vec[1].size());
        int cur1 = vec[1].size()/2;
        int cur0 = (vec[1].size()%2 == 1) ? (vec[0].size()/2)+2 : vec[0].size()/2;
        if(cur0 > vec[0].size()) cur0 = vec[0].size();
        // printf("-- %d %d\n",cur0,cur1);
        vector<int> tmp;
        for(int i=0;i<cur0;i++)
            tmp.push_back(vec[0][i]);
        for(int i=0;i<cur1;i++)
            tmp.push_back(vec[1][i]);
        bool ans = Ask(tmp);
        
        vector<int> nxt[2];
        if(ans)
        {
            for(int i=0;i<vec[0].size();i++)
                if(i < cur0) nxt[0].push_back(vec[0][i]);
                else nxt[1].push_back(vec[0][i]);
            for(int i=0;i<vec[1].size();i++)
                if(i < cur1) nxt[0].push_back(vec[1][i]);
        }
        else
        {
            for(int i=0;i<vec[0].size();i++)
                if(i >= cur0) nxt[0].push_back(vec[0][i]);
                else nxt[1].push_back(vec[0][i]);
            for(int i=0;i<vec[1].size();i++)
                if(i >= cur1) nxt[0].push_back(vec[1][i]);
        }
        vec[0] = nxt[0];
        vec[1] = nxt[1];
    }
    // printf("%d\n",cnt);
    for(auto &p : vec[0])
    {
        printf("! %d\n",p);
        fflush(stdout);
        scanf("%s",s+1);
        if(s[2] == ')') return 0;
    }
    for(auto &p : vec[1])
    {
        printf("! %d\n",p);
        fflush(stdout);
        scanf("%s",s+1);
        if(s[2] == ')') return 0;
    }
}