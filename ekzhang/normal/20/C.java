import java.util.*;
import java.io.*;

public class T20C {
	static int N, M;
	static List<Map<Integer, Long>> adj = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		for (int i = 0; i < N; i++) {
			adj.add(new HashMap<Integer, Long>());
		}
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			long w = Long.parseLong(st.nextToken());
			if (a == b) continue;
			a--; b--;
			if (adj.get(a).containsKey(b)) {
				if (adj.get(a).get(b) > w) {
					adj.get(a).put(b, w);
					adj.get(b).put(a, w);
				}
			}
			else {
				adj.get(a).put(b, w);
				adj.get(b).put(a, w);
			}
		}
		PriorityQueue<long[]> pq = new PriorityQueue<long[]>(M, (a, b) -> (int) (a[0] - b[0]));
		boolean[] visited = new boolean[N];
		long[] dist = new long[N];
		int[] pred = new int[N];
		for (int i = 0; i < N; i++) {
			pred[i] = -1;
			dist[i] = i == 0 ? 0 : Long.MAX_VALUE;
		}
		pq.add(new long[] { dist[0], 0 });
		while (!pq.isEmpty()) {
			long[] p = pq.poll();
			long d = p[0];
			int v = (int) p[1];
			if (visited[v]) {
				continue;
			}
			visited[v] = true;
			for (Map.Entry<Integer, Long> e : adj.get(v).entrySet()) {
				int n = e.getKey();
				long edgeWeight = e.getValue();
				if (d + edgeWeight < dist[n]) {
					dist[n] = d + edgeWeight;
					pred[n] = v;
					pq.add(new long[] { dist[n], n });
				}
			}
		}

		if (!visited[N - 1]) {
			System.out.println(-1);
			return;
		}

		List<Integer> path = new ArrayList<Integer>();
		int currentNode = N - 1;
		while (currentNode != -1) {
			path.add(currentNode);
			currentNode = pred[currentNode];
		}
		for (int i = path.size() - 1; i >= 0; i--) {
			System.out.print(path.get(i) + 1 + " ");
		}
		System.out.println();
	}
}