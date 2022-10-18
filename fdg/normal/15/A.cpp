#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;


int main()
{
        int n,t,a=0,b;
        scanf("%d%d",&n,&t);
        vector<int> coord(n,0);
        vector <int> size(2080,0);
        for(int i=0;i<n;i++)
        {
                scanf("%d%d",&coord[i],&a);
                size[coord[i]+1001]=a;
        }
        sort(coord.begin(),coord.end());
        int ans=2;
        for(int i=0;i<coord.size()-1;i++)
        {
                double dist=coord[i+1]-coord[i]-(double(size[coord[i+1]+1001]+size[coord[i]+1001]))/2;
                if (dist==t) ans++;
                if (dist>t) ans+=2;
        }
        printf("%d\n",ans);
        return 0;
}