import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class TaskE implements Runnable {
	
	class Task implements Comparable<Task> {
		public int t, s, p, id;
		
		Task(int t, int s, int p, int id) {
			this.t = t;
			this.s = s;
			this.p = p;
			this.id = id;
		}
		
		private int sign(int x) {
			if (x < 0) {
				return -1;
			}
			
			if (x > 0) {
				return 1;
			}
			
			return 0;
		}
		
		@Override
		public int compareTo(Task arg0) {
			// TODO Auto-generated method stub
			return sign(t - arg0.t);
		}
	}

	class ActivatingTask implements Comparable<ActivatingTask> {
		public int t, s, p, id;
		public int printed;
		
		ActivatingTask(int t, int s, int p, int id) {
			this.t = t;
			this.s = s;
			this.p = p;
			this.id = id;
			
			this.printed = 0;
		}
		
		private int sign(int x) {
			if (x < 0) {
				return -1;
			}
			
			if (x > 0) {
				return 1;
			}
			
			return 0;
		}
		
		@Override
		public int compareTo(ActivatingTask arg0) {
			// TODO Auto-generated method stub
			return -sign(p - arg0.p);
		}
	}
	
	private long finishedTime[];
	
	private long ok(boolean sign, int n, Task tasks[], int priority) throws IOException {
		
		if (sign) {
			finishedTime = new long[n];
		}
		
		Queue<ActivatingTask> q = new PriorityQueue<ActivatingTask>();
		int ptr = 0;
		long nowTime = 0;
		while (true) {
			
			while (ptr < n && tasks[ptr].t == nowTime) {
				q.offer(new ActivatingTask(tasks[ptr].t, tasks[ptr].s, tasks[ptr].p == -1 ? priority : tasks[ptr].p, tasks[ptr].id));
				++ptr;
			}
			
			if (q.size() == 0) {
				
				if (sign && ptr == n) {
					return 0;
				}
				
				if (ptr == n) {
					throw new IOException();
				} else {
					nowTime = tasks[ptr].t;
					continue;
				}
			}
			
			ActivatingTask e = q.poll();
			long nextTime = e.s - e.printed + nowTime;
			if (ptr < n && tasks[ptr].t < nextTime) {
				nextTime = tasks[ptr].t;
		//		System.out.println("task[ptr].t = " + tasks[ptr].t + " " + nowTime);
			}
			
			e.printed += nextTime - nowTime;
			nowTime = nextTime;
			
			if (e.printed < e.s) {
				q.offer(e);
			} else {
		//		System.out.println(e.printed + " " + e.s + " " + nowTime);
				
				if (sign) {
					finishedTime[e.id] = nowTime;
				}
				
				if (e.p == priority && !sign) {
					return nowTime;
				}
			}
		}
	}

    private void solve() throws IOException {
    	int n = nextInt();
    	Task tasks[] = new Task[n];
    	int pri[] = new int[n + 2];
    	for (int i = 0; i < n; ++i) {
    		int t = nextInt();
    		int s = nextInt();
    		int p = nextInt();
    		
    		tasks[i] = new Task(t, s, p, i);
    		pri[i] = p;
    	}
    	
    	long T = nextLong();
    	
    	pri[n] = 0;
    	pri[n + 1] = Integer.MAX_VALUE;
    	
    	Arrays.sort(tasks);
    	Arrays.sort(pri);
    	
    	ArrayList<Integer> goodPriorities = new ArrayList<Integer>();
    	for (int i = 0; i < n + 1; ++i) {
    		if (pri[i] + 1 != pri[i + 1]) {
    			goodPriorities.add(pri[i] + 1);
    		}
    	}
    	
    	int low = 0, high = goodPriorities.size() - 1;
    	while (low < high) {
    		int mid = ((low + high) >> 1) + 1;
    		if (ok(false, n, tasks, goodPriorities.get(mid)) < T) {
    			high = mid - 1;
    		} else {
    			low = mid;
    		}
    	}
    	
    	ok(true, n, tasks, goodPriorities.get(low));
    	writer.println(goodPriorities.get(low));
    	for (int i = 0; i < n; ++i) {
    		
    		if (i != 0) {
    			writer.print(" ");
    		}
    		
    		writer.print(finishedTime[i]);
    	}
    	
    	writer.println();
    	
    	
    }

    public static void main(String[] args) {
        new TaskE().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new FileReader("input.txt"));
            tokenizer = null;
            writer = new PrintWriter(new FileWriter("output.txt"));
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