# include<bits/stdc++.h>

# define mp make_pair

using namespace std;

int nnnn,i,j,k,c,a[200005];

int lft[200005],rgt[200005];

stack< int >st;

pair< int,pair< int,int > >p[200005];

map< int,int >d,used;

set< int >st1;

set< int >::iterator it;

vector< vector< int > >v(200005);

main()
{
    // farhod farhod farhod
    scanf("%d",&nnnn);

    for(i=1;i<=nnnn;i++){

        scanf("%d",&a[i]);

    }

    for(i=1;i<=nnnn;i++){

        st1.insert(-a[i]);

        while(!st.empty() && a[st.top()]>=a[i])st.pop();

        if(!st.empty())lft[i]=st.top();

        st.push(i);

    }

    while(!st.empty())st.pop();

    for(i=nnnn;i>=1;i--){

        while(!st.empty() && a[st.top()]>=a[i])st.pop();

        if(!st.empty())rgt[i]=st.top();

        else rgt[i]=nnnn+1;

        st.push(i);

    }

    for(i=1;i<=nnnn;i++){

        d[a[i]]=max(d[a[i]],rgt[i]-lft[i]-1);

    }

    for(i=1;i<=nnnn;i++){

        if(!used[a[i]]){

            used[a[i]]=1;

            v[d[a[i]]].push_back(a[i]);

        }

    }

    for(i=1;i<=nnnn;i++){

        it=st1.begin();

        printf("%d ",-*it);

        for(j=0;j<v[i].size();j++){

            c=v[i][j];

            st1.erase(-c);

        }
    }

    return 0;
}