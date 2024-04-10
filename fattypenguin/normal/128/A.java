import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.*;
import java.util.StringTokenizer;

public class Main implements Runnable {
    
    static int dx[] = {1,-1,0,0,1,1,-1,-1,0},
               dy[] = {0,0,1,-1,-1,1,1,-1,0};
    String map[];
    boolean win;
    
    class Pair
    {
        int x,y;
        public Pair() {}
        public Pair(int x,int y)
        {
            this.x = x;
            this.y = y;
        }
    }
    
    ArrayList<Pair> st;
    
    private boolean ok(int x,int y)
    {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
    
    private void gao(int step,int x,int y)
    {
        if (win) return;
        for (Pair s: st)
            if (step > 0 && s.x+step-1 == x && s.y == y)
                return;
        if (x == 0 && y == 7)
        {
            win = true;
            return;
        }
        //writer.println(x+" "+y);
        int count = 0;
        for (Pair s : st)
        {
            if (s.x+step == x && s.y == y)
                return;
            if (s.x + step >= 8) ++count;
        }
        if (count == st.size())
        {
            win = true;
            return;
        }
        for (int i = 0;i < 9;++i)
        {
            int xx = x + dx[i],yy = y + dy[i];
            if (ok(xx,yy))
                gao(step+1,xx,yy);
        }
    }

    private void solve() throws IOException {
        map = new String[8];
        for (int i = 0;i < 8;++i)
            map[i] = nextToken();
        Pair begin = new Pair();
        st = new ArrayList<Pair>();
        st.clear();
        for (int i = 0;i < 8;++i)
        {
            for (int j = 0;j < 8;++j)
            {
                if (map[i].charAt(j) == 'S')
                    st.add(new Pair(i,j));
                if (map[i].charAt(j) == 'M')
                    begin = new Pair(i,j);
            }
        }
        win = false;
        gao(0,begin.x,begin.y);
        writer.println(win ? "WIN" : "LOSE");       
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