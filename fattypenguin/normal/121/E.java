import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
    
    class Node
    {
        int total,next,delta;
        public Node() {}
    }
    
    int init[],next[];
    Node tree[];

    private void buildTree(int left,int right,int p)
    {
        //System.out.println(left + " " + right + " " + p);
        tree[p] = new Node();
        tree[p].delta = 0;
        if (left == right)
        {
            tree[p].delta = init[left];
            if (0 == next[init[left]])
            {
                tree[p].total = 1;
                tree[p].next = 1;
            }
            else 
            {
                tree[p].total = 0;
                tree[p].next = next[init[left]] - init[left];   
            }
            return;
        }
        int mid = (left + right) >> 1;
        buildTree(left,mid,p*2);
        buildTree(mid+1,right,p*2+1);
        up(p);
    }
    
    private int calc(int left,int right,int l,int r,int p)
    {
        if (l <= left && r >= right)
            return tree[p].total;
        int mid = (left + right) >> 1, ret = 0;
        down(p);
        if (l <= mid) ret = calc(left,mid,l,r,p*2);
        if (r > mid) ret += calc(mid+1,right,l,r,p*2+1);
        up(p);
        return ret;
    }
    
    private void addWholeNode(int left,int right,int l,int r,int p) throws IOException
    {
        if (tree[p].next > 0) return;
        if (left == right)
        {
            if (next[tree[p].delta] == 0)
            {
                tree[p].total = 1;
                tree[p].next = 1;
            }
            else
            {
                tree[p].total = 0;
                tree[p].next = next[tree[p].delta] - tree[p].delta;
            }
            return;
        }
        int mid = (left + right) >> 1;
        down(p);
        if (l <= mid) addWholeNode(left,mid,l,r,p*2);
        if (r > mid) addWholeNode(mid+1,right,l,r,p*2+1);
        up(p);
    }
    
    private void add(int left,int right,int l,int r,int p,int d) throws IOException
    {
    //  System.out.printf("here i am %d %d %d %d %d\n", left, right, l ,r , p);
        if (l <= left && r >= right)
        {
            tree[p].delta += d;
            tree[p].next -= d;
            addWholeNode(left,right,l,r,p);
            return;
        }
        down(p);
        int mid = (left + right) >> 1;
        if (l <= mid) add(left,mid,l,r,p*2,d);
        if (r > mid) add(mid+1,right,l,r,p*2+1,d);
        up(p);
    }
    
    private void up(int p)
    {
        tree[p].next = Math.min(tree[p*2].next,tree[p*2+1].next);
        tree[p].total = tree[p*2].total + tree[p*2+1].total;
    }
    
    private void down(int p)
    {
        //writer.println(p);
        if (0 == tree[p].delta) return;
        tree[p*2].delta += tree[p].delta;
        tree[p*2].next -= tree[p].delta;
        tree[p*2+1].delta += tree[p].delta;
        tree[p*2+1].next -= tree[p].delta;
        tree[p].delta = 0;
    }
    
    ArrayList<Integer> lucky;
    Integer luckyNumber[];
    
    private void gen(int now)
    {
        if (now > 10000) return;
        lucky.add(now);
        gen(now*10+4);
        gen(now*10+7);
    }
    
    private void initalize()
    {
        gen(0);
        luckyNumber = (Integer[]) lucky.toArray(new Integer[lucky.size()]);
        Arrays.sort(luckyNumber);
        int last = 0;
        for (int i = 0;i < luckyNumber.length;++i)
        {
            for (;last<luckyNumber[i];++last)
                next[last] = luckyNumber[i];
            next[last++] = 0; 
        }
        for (;last < 10000;++last)
            next[last] = 0x7f7f7f7f;
    }
    
    private void solve() throws IOException {
    //  System.out.println("ok");
        int n = nextInt(), m = nextInt();
        tree = new Node[4*n];
        init = new int[n];
        next = new int[10007];
        lucky = new ArrayList<Integer>();
        for (int i = 0;i < n;++i) init[i]= nextInt(); 
        initalize();
        buildTree(0,n-1,1);
        for (int i = 0;i < m;++i)
        {
            String opt = nextToken();
            if (opt.compareTo("count")==0)
            {
                //System.out.println(opt);
                int l = nextInt(), r = nextInt();
                writer.println(calc(0,n-1,l-1,r-1,1));
            }
            else
            {
                int l = nextInt(), r = nextInt(), d = nextInt();
                add(0,n-1,l-1,r-1,1,d);
            }
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}